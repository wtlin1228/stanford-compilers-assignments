

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "semant.h"
#include "utilities.h"
#include "set"


extern int semant_debug;
extern char *curr_filename;

//////////////////////////////////////////////////////////////////////
//
// Symbols
//
// For convenience, a large number of symbols are predefined here.
// These symbols include the primitive type and method names, as well
// as fixed names used by the runtime system.
//
//////////////////////////////////////////////////////////////////////
static Symbol 
    arg,
    arg2,
    Bool,
    concat,
    cool_abort,
    copy,
    Int,
    in_int,
    in_string,
    IO,
    length,
    Main,
    main_meth,
    No_class,
    No_type,
    Object,
    out_int,
    out_string,
    prim_slot,
    self,
    SELF_TYPE,
    Str,
    str_field,
    substr,
    type_name,
    val;
//
// Initializing the predefined symbols.
//
static void initialize_constants(void)
{
    arg         = idtable.add_string("arg");
    arg2        = idtable.add_string("arg2");
    Bool        = idtable.add_string("Bool");
    concat      = idtable.add_string("concat");
    cool_abort  = idtable.add_string("abort");
    copy        = idtable.add_string("copy");
    Int         = idtable.add_string("Int");
    in_int      = idtable.add_string("in_int");
    in_string   = idtable.add_string("in_string");
    IO          = idtable.add_string("IO");
    length      = idtable.add_string("length");
    Main        = idtable.add_string("Main");
    main_meth   = idtable.add_string("main");
    //   _no_class is a symbol that can't be the name of any 
    //   user-defined class.
    No_class    = idtable.add_string("_no_class");
    No_type     = idtable.add_string("_no_type");
    Object      = idtable.add_string("Object");
    out_int     = idtable.add_string("out_int");
    out_string  = idtable.add_string("out_string");
    prim_slot   = idtable.add_string("_prim_slot");
    self        = idtable.add_string("self");
    SELF_TYPE   = idtable.add_string("SELF_TYPE");
    Str         = idtable.add_string("String");
    str_field   = idtable.add_string("_str_field");
    substr      = idtable.add_string("substr");
    type_name   = idtable.add_string("type_name");
    val         = idtable.add_string("_val");
}

ClassTable::ClassTable(Classes classes) : semant_errors(0) , error_stream(cerr) {
    this->install_basic_classes();
    
    // use the simple iterator of list_node to iterate through classes
    for (int i = classes->first(); classes->more(i); i = classes->next(i)) {
        this->add_class(classes->nth(i));
    }
}

void ClassTable::install_basic_classes() {

    // The tree package uses these globals to annotate the classes built below.
   // curr_lineno  = 0;
    Symbol filename = stringtable.add_string("<basic class>");
    
    // The following demonstrates how to create dummy parse trees to
    // refer to basic Cool classes.  There's no need for method
    // bodies -- these are already built into the runtime system.
    
    // IMPORTANT: The results of the following expressions are
    // stored in local variables.  You will want to do something
    // with those variables at the end of this method to make this
    // code meaningful.

    // 
    // The Object class has no parent class. Its methods are
    //        abort() : Object    aborts the program
    //        type_name() : Str   returns a string representation of class name
    //        copy() : SELF_TYPE  returns a copy of the object
    //
    // There is no need for method bodies in the basic classes---these
    // are already built in to the runtime system.

    Class_ Object_class =
	class_(Object, 
	       No_class,
	       append_Features(
			       append_Features(
					       single_Features(method(cool_abort, nil_Formals(), Object, no_expr())),
					       single_Features(method(type_name, nil_Formals(), Str, no_expr()))),
			       single_Features(method(copy, nil_Formals(), SELF_TYPE, no_expr()))),
	       filename);
    
    this->add_class(Object_class);

    // 
    // The IO class inherits from Object. Its methods are
    //        out_string(Str) : SELF_TYPE       writes a string to the output
    //        out_int(Int) : SELF_TYPE            "    an int    "  "     "
    //        in_string() : Str                 reads a string from the input
    //        in_int() : Int                      "   an int     "  "     "
    //
    Class_ IO_class = 
	class_(IO, 
	       Object,
	       append_Features(
			       append_Features(
					       append_Features(
							       single_Features(method(out_string, single_Formals(formal(arg, Str)),
										      SELF_TYPE, no_expr())),
							       single_Features(method(out_int, single_Formals(formal(arg, Int)),
										      SELF_TYPE, no_expr()))),
					       single_Features(method(in_string, nil_Formals(), Str, no_expr()))),
			       single_Features(method(in_int, nil_Formals(), Int, no_expr()))),
	       filename);  
    this->add_class(IO_class);

    //
    // The Int class has no methods and only a single attribute, the
    // "val" for the integer. 
    //
    Class_ Int_class =
	class_(Int, 
	       Object,
	       single_Features(attr(val, prim_slot, no_expr())),
	       filename);
    this->add_class(Int_class);

    //
    // Bool also has only the "val" slot.
    //
    Class_ Bool_class =
	class_(Bool, Object, single_Features(attr(val, prim_slot, no_expr())),filename);
    this->add_class(Bool_class);

    //
    // The class Str has a number of slots and operations:
    //       val                                  the length of the string
    //       str_field                            the string itself
    //       length() : Int                       returns length of the string
    //       concat(arg: Str) : Str               performs string concatenation
    //       substr(arg: Int, arg2: Int): Str     substring selection
    //       
    Class_ Str_class =
	class_(Str, 
	       Object,
	       append_Features(
			       append_Features(
					       append_Features(
							       append_Features(
									       single_Features(attr(val, Int, no_expr())),
									       single_Features(attr(str_field, prim_slot, no_expr()))),
							       single_Features(method(length, nil_Formals(), Int, no_expr()))),
					       single_Features(method(concat, 
								      single_Formals(formal(arg, Str)),
								      Str, 
								      no_expr()))),
			       single_Features(method(substr, 
						      append_Formals(single_Formals(formal(arg, Int)), 
								     single_Formals(formal(arg2, Int))),
						      Str, 
						      no_expr()))),
	       filename);
    this->add_class(Str_class);
}

////////////////////////////////////////////////////////////////////
//
// semant_error is an overloaded function for reporting errors
// during semantic analysis.  There are three versions:
//
//    ostream& ClassTable::semant_error()                
//
//    ostream& ClassTable::semant_error(Class_ c)
//       print line number and filename for `c'
//
//    ostream& ClassTable::semant_error(Symbol filename, tree_node *t)  
//       print a line number and filename
//
///////////////////////////////////////////////////////////////////

ostream& ClassTable::semant_error(Class_ c)
{                                                             
    return semant_error(c->get_filename(),c);
}    

ostream& ClassTable::semant_error(Symbol filename, tree_node *t)
{
    error_stream << filename << ":" << t->get_line_number() << ": ";
    return semant_error();
}

ostream& ClassTable::semant_error()                  
{                                                 
    semant_errors++;                            
    return error_stream;
} 

void ClassTable::add_class(Class_ c) {
    Symbol name = c->get_name();
    Symbol parent = c->get_parent();

    // error handling
    if (class_map.count(name) == 1) {
        this->semant_error(c) << "Class " << name << " has already been defined.\n";
        return;
    }
    if (
        parent == Bool || 
        parent == Int || 
        parent == SELF_TYPE || 
        parent == Str
    ) {
        this->semant_error(c) << "Class " << name << " cannot inherit class " << parent << ".\n";
        return;
    }
    if (name == SELF_TYPE) {
        this->semant_error(c) << "Redefinition of " << name << " is not allowed.\n";
        return;
    }
    
    // it's a valid class
    this->class_map[name] = c;
    this->inheritance_graph[name] = parent;
}

/*
 * `is_main_class_defined` returns true if Main class is defined.
 */
bool ClassTable::is_main_class_defined() {
    if (this->class_map.count(Main) == 0) {
        this->semant_error() << "Class Main is not defined.\n";
        return false;
    }
    return true;
}

/*
 * `are_all_parent_classes_defined` returns true if all classes inherited 
 * are defined.
 * 
 * Time complexity: O(n), where n is the size of class list
 * Space complexity: O(n), where n is the size of class list
 */
bool ClassTable::are_all_parent_classes_defined() {
    for (
        std::map<Symbol, Symbol>::iterator it = this->inheritance_graph.begin(); 
        it != this->inheritance_graph.end(); 
        ++it
    ) {
        Symbol child = it->first;
        Symbol parent = it->second;
        if (child == Object) {
            continue;
        }
        if (this->class_map.count(parent) == 0) {
            this->semant_error() << "Class "
                << child
                << " inherits from an undefined class "
                << parent
                << ".\n";
            return false;
        }
    }
    return true;
}

/*
 * `is_acyclic` returns true if the inheritance graph has no cycles.
 * 
 * Time complexity: O(n), where n is the size of class list
 * Space complexity: O(n), where n is the size of class list
 */
bool ClassTable::is_acyclic() {
    // Each Symbol in the visited_classes has no cycles
    std::set<Symbol> visited_classes;
    std::set<Symbol> path;
    for (
        std::map<Symbol, Symbol>::iterator it = this->inheritance_graph.begin(); 
        it != this->inheritance_graph.end(); 
        ++it
    ) {
        Symbol child = it->first;
        Symbol parent = it->second;
        if (visited_classes.count(child) != 0) {
            // This class had been verified as no inheritance cycle
            continue;
        }
        path.insert(child);
        while (parent != No_class) {
            if (visited_classes.count(parent) != 0) {
                break;
            }
            if (path.count(parent) != 0) {
                semant_error(this->class_map.at(child)) << "There exists a circular dependency for "
                    << parent
                    << " (the ancestor of "
                    << child
                    << ")"
                    << ".\n";
                return false;
            }
            path.insert(parent);
            parent = this->inheritance_graph.at(parent);
        }
        // Mark the Symbols of the path as visited
        for (
            std::set<Symbol>::iterator it = path.begin(); 
            it != path.end(); 
            ++it
        ) {
            visited_classes.insert(*it);
        }
        // Reset path for next iteration
        path.clear();
    }
    return true;
}

/*
 * `init_inheritance_level_map` initializes `inheritance_level_map`.
 * 
 * Time complexity: O(n), where n is the size of class list
 * Space complexity: O(n), where n is the size of class list
 */
void ClassTable::init_inheritance_level_map() {
    // TODO: Not implemented
}

/*
 * `lub` returns the least upper bound for two classes.
 * 
 * time complexity: O(l), where l is the longest inheritance chain
 * space complexity: O(1)
 */
Symbol ClassTable::lub(Symbol c1, Symbol c2) {
    // TODO: Not implemented
}

void raise_error() {
    cerr << "Compilation halted due to static semantic errors." << endl;
    exit(1);
}

/*   This is the entry point to the semantic checker.

     Your checker should do the following two things:

     1) Check that the program is semantically correct
     2) Decorate the abstract syntax tree with type information
        by setting the `type' field in each Expression node.
        (see `tree.h')

     You are free to first do 1), make sure you catch all semantic
     errors. Part 2) can be done in a second stage, when you want
     to build mycoolc.
 */
void program_class::semant()
{
    initialize_constants();

    // 1. Look at all classes and build an inheritance graph.
    ClassTable *classtable = new ClassTable(classes);
    
    // 2. Check that graph is well-formed.
    if (
        classtable->errors() ||
        !classtable->is_main_class_defined() ||
        !classtable->are_all_parent_classes_defined() ||
        !classtable->is_acyclic()
    ) {
        raise_error();
    }

    classtable->init_inheritance_level_map();

    /*
     * 3. For each class
     *    (a) Traverse the AST, gathering all visible declarations in a symbol table.
     *    (b) Check each expression for type correctness.
     *    (c) Annotate the AST with types.
     */
    for (int i = classes->first(); classes->more(i); i = classes->next(i)) {
        // TODO: handle scope & type check
    }
    if (classtable->errors()) {
        raise_error();
    }
}


