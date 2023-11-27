class X {
    -- x: Int <- 5;

    -- get_name(a: Int, b: Bool): String { "X" };
};
class Y inherits X {
    -- y: Bool <- true;

    yyyyy: X <- self;
    zzzzz: SELF_TYPE <- new X;
        
    -- get_name(a: Int, b: Bool, c: AAA, a: String): String { "Y" };
    -- get_phone(): String { "0988777123" };
};
-- class Z inherits Y {};

-- class A inherits B {};
-- class B inherits C {};
-- class C inherits B {};

-- class D inherits E {};

class Main {};
