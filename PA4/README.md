# Semantic Analyzer

## Workflow

1. Ensure Main class is defined with a main method.
1. Ensure all classes are defined.
1. Ensure no circular inheritances.
1. Ensure no inherited attributes are redefined.
1. Ensure redefined inherited methods have exactly the same types for both formal parameters and return type.
1. Type check!

## Errors

1. Inherited class is not defined.

   Error: message: Class {class_name} inherits from an undefined class {inherited_class_name}.

   ```
   class A inherits Foo {};
   ```

1. Circular inheritance is not allowed.

   Error message: Class {class_name}, or an ancestor of {class_name}, is involved in an inheritance cycle.

   ```
   class A inherits B {};
   class B inherits A {};
   ```

1. Inherited attributes cannot be redefined.

   Error message: Attribute {attribute_name} is an attribute of an inherited class.

   ```
   class A {
     a: Int <- 1;
   };

   class B inherits A {
     a: Int <- 2;
   };
   ```

1. Inherited methods must have exactly the same types for formal parameters and the return type.

   Note: return type is checked first

   Error message 1: In redefined method {method_name}, return type {return_type} is different from original return type {original_return_type}.

   ```
   class A {
     f(): Int { 1 };
   };

   class B inherits A {
     f(): String { "1" };
   };
   ```

   Error Message 2: In redefined method {method_name}, parameter type {parameter_type} is different from original type {original_parameter_type}.

   ```
   class A {
     f(a: Int): Int { 1 };
   };

   class B inherits A {
     f(a: String): Int { 2 };
   };
   ```

1. Type is undefined.

   - Formal:

     Error message: Class {parameter_type} of formal parameter {parameter_name} is undefined.

1. Multiple declarations.

   - Formal:

     Error message: Formal parameter {parameter_name} is multiply defined.

1. Not allowed types.

   - Formal:

     Error message: Formal parameter {parameter_name} cannot have type SELF_TYPE.

1. Type mismatch.

   - Method:

     Error message: Inferred return type {inferred_return_type} of method {method_name} does not conform to declared return type {method_return_type}.
