class X {
    attr_1: Bool <- 1 + true;
    attr_2: Bool <- 1 - true;    
    attr_3: Bool <- 1 * true;    
    attr_4: Bool <- 1 / true;    
    attr_5: Bool <- ~true;    
    attr_6: Bool <- 1 < true;    
    attr_7: Bool <- 1 = true;    
    attr_8: Bool <- 1 <= true;    
    attr_9: Bool <- not 1;    
};

class Y inherits X {

};

class Main {};
