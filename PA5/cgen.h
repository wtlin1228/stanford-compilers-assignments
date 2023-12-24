#include <assert.h>
#include <stdio.h>
#include "emit.h"
#include "cool-tree.h"
#include "symtab.h"
#include <map>
#include <vector>

enum Basicness     {Basic, NotBasic};
#define TRUE 1
#define FALSE 0

class CgenClassTable;
typedef CgenClassTable *CgenClassTableP;

class CgenNode;
typedef CgenNode *CgenNodeP;

class CgenClassTable : public SymbolTable<Symbol,CgenNode> {
private:
   List<CgenNode> *nds;
   ostream& str;
   int stringclasstag;
   int intclasstag;
   int boolclasstag;
   int next_classtag;
   std::map<Symbol, std::map<Symbol, int> >           class_attr_index_table;
   std::map<Symbol, std::vector<Symbol> >             class_attrs_table;
   std::map<Symbol, std::map<Symbol, int> >           class_method_index_table;
   std::map<Symbol, std::vector<Symbol> >             class_methods_table;
   std::map<Symbol, std::map<Symbol, Symbol> >        class_method_owned_by_table;
   std::map<Symbol, std::map<Symbol, method_class*> > class_method_definition_table;

// lookup tables
   void build_class_lookup_tables();
   int get_attr_index(Symbol c, Symbol attr) { return class_attr_index_table[c][attr]; };
   std::vector<Symbol>& get_attrs(Symbol c) { return class_attrs_table[c]; };
   int get_method_index(Symbol c, Symbol method) { return class_method_index_table[c][method]; };
   std::vector<Symbol>& get_methods(Symbol c) { return class_methods_table[c]; };
   Symbol get_method_owned_by(Symbol c, Symbol method) { return class_method_owned_by_table[c][method]; };
   method_class* get_method_definition(Symbol c, Symbol method) { return class_method_definition_table[c][method]; };

// The following methods emit code for
// constants and global declarations.

   void code_global_data();
   void code_global_text();
   void code_bools(int);
   void code_select_gc();
   void code_constants();

// The following methods emit code for
// all classes.
   void code_class_name_table();
   void code_class_object_table();
   void code_class_dispatch_tables();
   void code_class_prototype_tables();
   void code_class_init_methods();
   void code_class_methods();

// The following creates an inheritance graph from
// a list of classes.  The graph is implemented as
// a tree of `CgenNode', and class names are placed
// in the base class symbol table.

   void install_basic_classes();
   void install_class(CgenNodeP nd);
   void install_classes(Classes cs);
   void build_inheritance_tree();
   void set_relations(CgenNodeP nd);
public:
   CgenClassTable(Classes, ostream& str);
   void code();
   CgenNodeP root();
};


class CgenNode : public class__class {
private: 
   CgenNodeP parentnd;                        // Parent of class
   List<CgenNode> *children;                  // Children of class
   Basicness basic_status;                    // `Basic' if class is basic
                                              // `NotBasic' otherwise

public:
   CgenNode(Class_ c,
            Basicness bstatus,
            CgenClassTableP class_table);

   void add_child(CgenNodeP child);
   List<CgenNode> *get_children() { return children; }
   void set_parentnd(CgenNodeP p);
   CgenNodeP get_parentnd() { return parentnd; }
   int basic() { return (basic_status == Basic); }
};

class BoolConst 
{
 private: 
  int val;
 public:
  BoolConst(int);
  void code_def(ostream&, int boolclasstag);
  void code_ref(ostream&) const;
};

