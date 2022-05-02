enum OBJECT_TYPE{
    TIP_1 = 1,
    TIP_2,
    TIP_3,
    TIP_4,
    TIP_5,
    TIP_6,
    TIP_7,
    TIP_8,
    MINE,
    FLAG
};

enum OBJECT_STATE{
    REGULAR = 0,
    // marked
    OPENED,
    // flag
    PUTFLAG,
    CURSOR
};