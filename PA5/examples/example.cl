
(*  Example cool program testing as many aspects of the code generator
    as possible.
 *)

class Main {
  a: A <- new A;

  main() : Int {{ 
    (new IO).out_int(a.f(8, 7));
    a.f(8, 7);
  }};
};

class A {
  a1: Int <- 42;
  a2: Int <- 43;
  f(x1 : Int, x2 : Int) : Int { a1 + a2 + x1 + x2 };
};
