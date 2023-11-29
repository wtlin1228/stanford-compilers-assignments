class Main inherits IO {
    b: B <- new B;
    main(): String {{
        out_string("hello world\n");

        b@A.foo(true, b, b, new A, b);
        (new C)@A.doo(1, b, b, b);
        b@A.boo(1, 2, 3);

        "do nothing";
    }};

};

class A {
    foo(a: Int, b: B, c: A, d: B): Int {
        {
            (new IO).out_string("dispatch A.foo()\n"); 
            5;
        }
    };
};

class B inherits A {
  foo(a: Int, b: B, c: A, d: B): Int {
    {
      (new IO).out_string("dispatch B.foo()\n"); 
      6;
    }
  };

};

class C {
  foo(a: Int, b: B, c: A, d: B): Int {
    {
      (new IO).out_string("dispatch C.foo()\n"); 
      7;
    }
  };

};
