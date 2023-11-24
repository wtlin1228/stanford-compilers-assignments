#ifndef SEMANT_H_
#define SEMANT_H_

#include <assert.h>
#include <iostream>
#include <map>  
#include "cool-tree.h"
#include "stringtab.h"
#include "symtab.h"
#include "list.h"

#define TRUE 1
#define FALSE 0

class ClassTable;
typedef ClassTable *ClassTableP;

// This is a structure that may be used to contain the semantic
// information such as the inheritance graph.  You may use it or not as
// you like: it is only here to provide a container for the supplied
// methods.

class ClassTable {
private:
  int semant_errors;
  void install_basic_classes();
  ostream& error_stream;
  std::map<Symbol, Class_> class_map;
  std::map<Symbol, Symbol> inheritance_graph;
  // inheritance_level_map will be used to find the lub (least upper bound)
  // level(Object) = 0
  // level(Str) = 1
  // level(A) = 3 if
  //   class A inherits B {};
  //   class B inherits C {};
  // Note: should only be used after init_inheritance_level_map().
  std::map<Symbol, int> inheritance_level_map;

public:
  ClassTable(Classes);
  int errors() { return semant_errors; }
  ostream& semant_error();
  ostream& semant_error(Class_ c);
  ostream& semant_error(Symbol filename, tree_node *t);
  void add_class(Class_ c);
  bool is_main_class_defined();
  bool are_all_parent_classes_defined();
  bool is_acyclic();
  void init_inheritance_level_map();
  Symbol lub(Symbol c1, Symbol c2);
};


#endif

