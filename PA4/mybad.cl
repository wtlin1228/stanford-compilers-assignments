class X {
    x: Int <- 5;

    get_name(a: Int, b: Bool, c: Int): String { "X" };
};
class Y inherits X {
    y: Bool <- true;
        
    get_name(a: Int, b: Bool): String { "Y" };
};
-- class Z inherits Y {};

-- class A inherits B {};
-- class B inherits C {};
-- class C inherits B {};

-- class D inherits E {};

class Main {};
