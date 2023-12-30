class Main inherits IO {
    aaa: A <- new D;
    main(): Object {
        case aaa of
            b : B => {
                out_string("Class type is now B\n");
                out_int(b.f());
                out_string("\n");
            };
            c : C => {
                out_string("Class type is now C\n");
                case c of
                    c : C => {
                        out_string("Class type is now C\n");
                        out_int(c.f());
                        out_string("\n");
                    };
                    d : D => {
                        out_string("Class type is now D\n");
                        out_int(d.f());
                        out_string("\n");
                    };
                    o : Object => out_string("Oooops\n");
                esac;
            };
            a : A => {
                out_string("Class type is now A\n");
                out_int(a.f());
                out_string("\n");
            };
            e : E => {
                out_string("Class type is now E\n");
                out_int(e.f());
                out_string("\n");
            };
            o : Object => out_string("Oooops\n");
        esac
    };
};

class A {
    f() : Int { 1 };
};

class B inherits A {
    f() : Int { 2 };
};

class C inherits B {
    f() : Int { 3 };
};

class D inherits C {
    f() : Int { 4 };
};

class E inherits D {
    f() : Int { 5 };
};

