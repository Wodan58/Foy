/* 1000 */ { Q0, IMMEDIATE, "false", false_, "A", "->  false", "Pushes the value false.\n" },
/* 1010 */ { Q0, IMMEDIATE, "true", true_, "A", "->  true", "Pushes the value true.\n" },
/* 1020 */ { Q0, IMMEDIATE, "maxint", maxint_, "A", "->  maxint", "Pushes largest integer (platform dependent). Typically it is 32 bits.\n" },
/* 1030 */ { Q0, OK, "setsize", setsize_, "A", "->  setsize", "Pushes the maximum number of elements in a set (platform dependent).\nTypically it is 32, and set members are in the range 0..31.\n" },
/* 1040 */ { Q0, OK, "stack", stack_, "A", ".. X Y Z  ->  .. X Y Z [Z Y X ..]", "Pushes the stack as a list.\n" },
/* 1050 */ { Q0, OK, "__symtabmax", __symtabmax_, "A", "->  I", "Pushes value of maximum size of the symbol table.\n" },
/* 1060 */ { Q0, OK, "__symtabindex", __symtabindex_, "A", "->  I", "Pushes current size of the symbol table.\n" },
/* 1070 */ { Q0, OK, "__dump", __dump_, "A", "->  [..]", "debugging only: pushes the dump as a list.\n" },
/* 1080 */ { Q0, OK, "conts", conts_, "A", "->  [[P] [Q] ..]", "Pushes current continuations. Buggy, do not use.\n" },
/* 1090 */ { Q0, OK, "autoput", autoput_, "A", "->  I", "Pushes current value of flag for automatic output, I = 0..2.\n" },
/* 1100 */ { Q0, OK, "undeferror", undeferror_, "A", "->  I", "Pushes current value of undefined-is-error flag.\n" },
/* 1110 */ { Q0, OK, "undefs", undefs_, "A", "->  [..]", "Push a list of all undefined symbols in the current symbol table.\n" },
/* 1120 */ { Q0, OK, "echo", echo_, "A", "->  I", "Pushes value of echo flag, I = 0..3.\n" },
/* 1130 */ { Q0, IGNORE_PUSH, "clock", clock_, "A", "->  I", "[IMPURE] Pushes the integer value of current CPU usage in milliseconds.\n" },
/* 1140 */ { Q0, IGNORE_PUSH, "time", time_, "A", "->  I", "[IMPURE] Pushes the current time (in seconds since the Epoch).\n" },
/* 1150 */ { Q0, OK, "rand", rand_, "A", "->  I", "[IMPURE] I is a random integer.\n" },
/* 1160 */ { Q0, OK, "__memorymax", __memorymax_, "A", "->  I", "Pushes value of total size of memory.\n" },
/* 1170 */ { Q0, IMMEDIATE, "stdin", stdin_, "A", "->  S", "[FOREIGN] Pushes the standard input stream.\n" },
/* 1180 */ { Q0, IMMEDIATE, "stdout", stdout_, "A", "->  S", "[FOREIGN] Pushes the standard output stream.\n" },
/* 1190 */ { Q0, IMMEDIATE, "stderr", stderr_, "A", "->  S", "[FOREIGN] Pushes the standard error stream.\n" },
/* 1200 */ { Q0, OK, "id", id_, "N", "->", "Identity function, does nothing.\nAny program of the form  P id Q  is equivalent to just  P Q.\n" },
/* 1210 */ { Q0, OK, "dup", dup_, "A", "X  ->  X X", "Pushes an extra copy of X onto stack.\n" },
/* 1220 */ { Q0, OK, "swap", swap_, "DDAA", "X Y  ->  Y X", "Interchanges X and Y on top of the stack.\n" },
/* 1230 */ { Q0, OK, "rollup", rollup_, "DDDAAA", "X Y Z  ->  Z X Y", "Moves X and Y up, moves Z down.\n" },
/* 1240 */ { Q0, OK, "rolldown", rolldown_, "DDDAAA", "X Y Z  ->  Y Z X", "Moves Y and Z down, moves X up.\n" },
/* 1250 */ { Q0, OK, "rotate", rotate_, "DDDAAA", "X Y Z  ->  Z Y X", "Interchanges X and Z.\n" },
/* 1260 */ { Q0, OK, "popd", popd_, "DDA", "Y Z  ->  Z", "As if defined by:   popd  ==  [pop] dip\n" },
/* 1270 */ { Q0, OK, "dupd", dupd_, "DDAAA", "Y Z  ->  Y Y Z", "As if defined by:   dupd  ==  [dup] dip\n" },
/* 1280 */ { Q0, OK, "swapd", swapd_, "DDDAAA", "X Y Z  ->  Y X Z", "As if defined by:   swapd  ==  [swap] dip\n" },
/* 1290 */ { Q0, OK, "rollupd", rollupd_, "DDDDAAAA", "X Y Z W  ->  Z X Y W", "As if defined by:   rollupd  ==  [rollup] dip\n" },
/* 1300 */ { Q0, OK, "rolldownd", rolldownd_, "DDDDAAAA", "X Y Z W  ->  Y Z X W", "As if defined by:   rolldownd  ==  [rolldown] dip\n" },
/* 1310 */ { Q0, OK, "rotated", rotated_, "DDDDAAAA", "X Y Z W  ->  Z Y X W", "As if defined by:   rotated  ==  [rotate] dip\n" },
/* 1320 */ { Q0, OK, "pop", pop_, "D", "X  ->", "Removes X from top of the stack.\n" },
/* 1330 */ { Q0, OK, "choice", choice_, "DDDA", "B T F  ->  X", "If B is true, then X = T else X = F.\n" },
/* 1340 */ { Q0, OK, "or", or_, "DDA", "X Y  ->  Z", "Z is the union of sets X and Y, logical disjunction for truth values.\n" },
/* 1350 */ { Q0, OK, "xor", xor_, "DDA", "X Y  ->  Z", "Z is the symmetric difference of sets X and Y,\nlogical exclusive disjunction for truth values.\n" },
/* 1360 */ { Q0, OK, "and", and_, "DDA", "X Y  ->  Z", "Z is the intersection of sets X and Y, logical conjunction for truth values.\n" },
/* 1370 */ { Q0, OK, "not", not_, "DA", "X  ->  Y", "Y is the complement of set X, logical negation for truth values.\n" },
/* 1380 */ { Q0, OK, "+\0plus", plus_, "DDA", "M I  ->  N", "Numeric N is the result of adding integer I to numeric M.\nAlso supports float.\n" },
/* 1390 */ { Q0, OK, "-\0minus", minus_, "DDA", "M I  ->  N", "Numeric N is the result of subtracting integer I from numeric M.\nAlso supports float.\n" },
/* 1400 */ { Q0, OK, "*\0ast", mul_, "DDA", "I J  ->  K", "Integer K is the product of integers I and J.  Also supports float.\n" },
/* 1410 */ { Q0, OK, "/\0divide", divide_, "DDA", "I J  ->  K", "Integer K is the (rounded) ratio of integers I and J.  Also supports float.\n" },
/* 1420 */ { Q0, OK, "rem", rem_, "DDA", "I J  ->  K", "Integer K is the remainder of dividing I by J.  Also supports float.\n" },
/* 1430 */ { Q0, OK, "div", div_, "DDAA", "I J  ->  K L", "Integers K and L are the quotient and remainder of dividing I by J.\n" },
/* 1440 */ { Q0, OK, "sign", sign_, "DA", "N1  ->  N2", "Integer N2 is the sign (-1 or 0 or +1) of integer N1,\nor float N2 is the sign (-1.0 or 0.0 or 1.0) of float N1.\n" },
/* 1450 */ { Q0, OK, "neg", neg_, "DA", "I  ->  J", "Integer J is the negative of integer I.  Also supports float.\n" },
/* 1460 */ { Q0, OK, "ord", ord_, "DA", "C  ->  I", "Integer I is the Ascii value of character C (or logical or integer).\n" },
/* 1470 */ { Q0, OK, "chr", chr_, "DA", "I  ->  C", "C is the character whose Ascii value is integer I (or logical or character).\n" },
/* 1480 */ { Q0, OK, "abs", abs_, "DA", "N1  ->  N2", "Integer N2 is the absolute value (0,1,2..) of integer N1,\nor float N2 is the absolute value (0.0 ..) of float N1.\n" },
/* 1490 */ { Q0, OK, "acos", acos_, "DA", "F  ->  G", "G is the arc cosine of F.\n" },
/* 1500 */ { Q0, OK, "asin", asin_, "DA", "F  ->  G", "G is the arc sine of F.\n" },
/* 1510 */ { Q0, OK, "atan", atan_, "DA", "F  ->  G", "G is the arc tangent of F.\n" },
/* 1520 */ { Q0, OK, "atan2", atan2_, "DDA", "F G  ->  H", "H is the arc tangent of F / G.\n" },
/* 1530 */ { Q0, OK, "ceil", ceil_, "DA", "F  ->  G", "G is the float ceiling of F.\n" },
/* 1540 */ { Q0, OK, "cos", cos_, "DA", "F  ->  G", "G is the cosine of F.\n" },
/* 1550 */ { Q0, OK, "cosh", cosh_, "DA", "F  ->  G", "G is the hyperbolic cosine of F.\n" },
/* 1560 */ { Q0, OK, "exp", exp_, "DA", "F  ->  G", "G is e (2.718281828...) raised to the Fth power.\n" },
/* 1570 */ { Q0, OK, "floor", floor_, "DA", "F  ->  G", "G is the floor of F.\n" },
/* 1580 */ { Q0, OK, "frexp", frexp_, "DAA", "F  ->  G I", "G is the mantissa and I is the exponent of F.\nUnless F = 0, 0.5 <= abs(G) < 1.0.\n" },
/* 1590 */ { Q0, OK, "ldexp", ldexp_, "DDA", "F I  ->  G", "G is F times 2 to the Ith power.\n" },
/* 1600 */ { Q0, OK, "log", log_, "DA", "F  ->  G", "G is the natural logarithm of F.\n" },
/* 1610 */ { Q0, OK, "log10", log10_, "DA", "F  ->  G", "G is the common logarithm of F.\n" },
/* 1620 */ { Q0, OK, "modf", modf_, "DAA", "F  ->  G H", "G is the fractional part and H is the integer part\n(but expressed as a float) of F.\n" },
/* 1630 */ { Q0, OK, "pow", pow_, "DDA", "F G  ->  H", "H is F raised to the Gth power.\n" },
/* 1640 */ { Q0, OK, "sin", sin_, "DA", "F  ->  G", "G is the sine of F.\n" },
/* 1650 */ { Q0, OK, "sinh", sinh_, "DA", "F  ->  G", "G is the hyperbolic sine of F.\n" },
/* 1660 */ { Q0, OK, "sqrt", sqrt_, "DA", "F  ->  G", "G is the square root of F.\n" },
/* 1670 */ { Q0, OK, "tan", tan_, "DA", "F  ->  G", "G is the tangent of F.\n" },
/* 1680 */ { Q0, OK, "tanh", tanh_, "DA", "F  ->  G", "G is the hyperbolic tangent of F.\n" },
/* 1690 */ { Q0, OK, "trunc", trunc_, "DA", "F  ->  I", "I is an integer equal to the float F truncated toward zero.\n" },
/* 1700 */ { Q0, OK, "localtime", localtime_, "DA", "I  ->  T", "Converts a time I into a list T representing local time:\n[year month day hour minute second isdst yearday weekday].\nMonth is 1 = January ... 12 = December;\nisdst is a Boolean flagging daylight savings/summer time;\nweekday is 1 = Monday ... 7 = Sunday.\n" },
/* 1710 */ { Q0, OK, "gmtime", gmtime_, "DA", "I  ->  T", "Converts a time I into a list T representing universal time:\n[year month day hour minute second isdst yearday weekday].\nMonth is 1 = January ... 12 = December;\nisdst is false; weekday is 1 = Monday ... 7 = Sunday.\n" },
/* 1720 */ { Q0, OK, "mktime", mktime_, "DA", "T  ->  I", "Converts a list T representing local time into a time I.\nT is in the format generated by localtime.\n" },
/* 1730 */ { Q0, OK, "strftime", strftime_, "DDA", "T S1  ->  S2", "Formats a list T in the format of localtime or gmtime\nusing string S1 and pushes the result S2.\n" },
/* 1740 */ { Q0, OK, "strtol", strtol_, "DDA", "S I  ->  J", "String S is converted to the integer J using base I.\nIf I = 0, assumes base 10,\nbut leading \"0\" means base 8 and leading \"0x\" means base 16.\n" },
/* 1750 */ { Q0, OK, "strtod", strtod_, "DA", "S  ->  R", "String S is converted to the float R.\n" },
/* 1760 */ { Q0, OK, "format", format_, "DDDDA", "N C I J  ->  S", "S is the formatted version of N in mode C\n('d or 'i = decimal, 'o = octal, 'x or\n'X = hex with lower or upper case letters)\nwith maximum width I and minimum width J.\n" },
/* 1770 */ { Q0, OK, "formatf", formatf_, "DDDDA", "F C I J  ->  S", "S is the formatted version of F in mode C\n('e or 'E = exponential, 'f = fractional,\n'g or G = general with lower or upper case letters)\nwith maximum width I and precision J.\n" },
/* 1780 */ { Q0, IGNORE_POP, "srand", srand_, "D", "I  ->", "[IMPURE] Sets the random integer seed to integer I.\n" },
/* 1790 */ { Q0, OK, "pred", pred_, "DA", "M  ->  N", "Numeric N is the predecessor of numeric M.\n" },
/* 1800 */ { Q0, OK, "succ", succ_, "DA", "M  ->  N", "Numeric N is the successor of numeric M.\n" },
/* 1810 */ { Q0, OK, "max", max_, "DDA", "N1 N2  ->  N", "N is the maximum of numeric values N1 and N2.  Also supports float.\n" },
/* 1820 */ { Q0, OK, "min", min_, "DDA", "N1 N2  ->  N", "N is the minimum of numeric values N1 and N2.  Also supports float.\n" },
/* 1830 */ { Q0, OK, "fclose", fclose_, "D", "S  ->", "[FOREIGN] Stream S is closed and removed from the stack.\n" },
/* 1840 */ { Q0, OK, "feof", feof_, "A", "S  ->  S B", "[FOREIGN] B is the end-of-file status of stream S.\n" },
/* 1850 */ { Q0, OK, "ferror", ferror_, "A", "S  ->  S B", "[FOREIGN] B is the error status of stream S.\n" },
/* 1860 */ { Q0, OK, "fflush", fflush_, "N", "S  ->  S", "[FOREIGN] Flush stream S, forcing all buffered output to be written.\n" },
/* 1870 */ { Q0, OK, "fgetch", fgetch_, "A", "S  ->  S C", "[FOREIGN] C is the next available character from stream S.\n" },
/* 1880 */ { Q0, OK, "fgets", fgets_, "A", "S  ->  S L", "[FOREIGN] L is the next available line (as a string) from stream S.\n" },
/* 1890 */ { Q0, OK, "fopen", fopen_, "DDA", "P M  ->  S", "[FOREIGN] The file system object with pathname P is opened with mode M\n(r, w, a, etc.) and stream object S is pushed; if the open fails, file:NULL\nis pushed.\n" },
/* 1900 */ { Q0, OK, "fread", fread_, "DA", "S I  ->  S L", "[FOREIGN] I bytes are read from the current position of stream S\nand returned as a list of I integers.\n" },
/* 1910 */ { Q0, OK, "fwrite", fwrite_, "D", "S L  ->  S", "[FOREIGN] A list of integers are written as bytes to the current position of\nstream S.\n" },
/* 1920 */ { Q0, OK, "fremove", fremove_, "DA", "P  ->  B", "[FOREIGN] The file system object with pathname P is removed from the file\nsystem. B is a boolean indicating success or failure.\n" },
/* 1930 */ { Q0, OK, "frename", frename_, "DDA", "P1 P2  ->  B", "[FOREIGN] The file system object with pathname P1 is renamed to P2.\nB is a boolean indicating success or failure.\n" },
/* 1940 */ { Q0, OK, "fput", fput_, "D", "S X  ->  S", "[FOREIGN] Writes X to stream S, pops X off stack.\n" },
/* 1950 */ { Q0, OK, "fputch", fputch_, "A", "S C  ->  S", "[FOREIGN] The character C is written to the current position of stream S.\n" },
/* 1960 */ { Q0, OK, "fputchars", fputchars_, "D", "S \"abc..\"  ->  S", "[FOREIGN] The string abc.. (no quotes) is written to the current position of\nstream S.\n" },
/* 1970 */ { Q0, OK, "fputstring", fputstring_, "D", "S \"abc..\"  ->  S", "[FOREIGN] == fputchars, as a temporary alternative.\n" },
/* 1980 */ { Q0, OK, "fseek", fseek_, "DDA", "S P W  ->  S B", "[FOREIGN] Stream S is repositioned to position P relative to whence-point W,\nwhere W = 0, 1, 2 for beginning, current position, end respectively.\n" },
/* 1990 */ { Q0, OK, "ftell", ftell_, "A", "S  ->  S I", "[FOREIGN] I is the current position of stream S.\n" },
/* 2000 */ { Q0, OK, "unstack", unstack_, "DP", "[X Y ..]  ->  ..Y X", "The list [X Y ..] becomes the new stack.\n" },
/* 2010 */ { Q0, OK, "cons", cons_, "DDA", "X A  ->  B", "Aggregate B is A with a new member X (first member for sequences).\n" },
/* 2020 */ { Q0, OK, "swons", swons_, "DDA", "A X  ->  B", "Aggregate B is A with a new member X (first member for sequences).\n" },
/* 2030 */ { Q0, OK, "first", first_, "DA", "A  ->  F", "F is the first member of the non-empty aggregate A.\n" },
/* 2040 */ { Q0, OK, "rest", rest_, "DA", "A  ->  R", "R is the non-empty aggregate A with its first member removed.\n" },
/* 2050 */ { Q0, OK, "compare", compare_, "DDA", "A B  ->  I", "I (=-1,0,+1) is the comparison of aggregates A and B.\nThe values correspond to the predicates <=, =, >=.\n" },
/* 2060 */ { Q0, OK, "at", at_, "DDA", "A I  ->  X", "X (= A[I]) is the member of A at position I.\n" },
/* 2070 */ { Q0, OK, "of", of_, "DDA", "I A  ->  X", "X (= A[I]) is the I-th member of aggregate A.\n" },
/* 2080 */ { Q0, OK, "size", size_, "DA", "A  ->  I", "Integer I is the number of elements of aggregate A.\n" },
/* 2090 */ { Q0, OK, "opcase", opcase_, "DA", "X [..[X Xs]..]  ->  X [Xs]", "Indexing on type of X, returns the list [Xs].\n" },
/* 2100 */ { Q1, OK, "case", case_, "DP", "X [..[X Y]..]  ->  Y i", "Indexing on the value of X, execute the matching Y.\n" },
/* 2110 */ { Q0, OK, "uncons", uncons_, "DAA", "A  ->  F R", "F and R are the first and the rest of non-empty aggregate A.\n" },
/* 2120 */ { Q0, OK, "unswons", unswons_, "DAA", "A  ->  R F", "R and F are the rest and the first of non-empty aggregate A.\n" },
/* 2130 */ { Q0, OK, "drop", drop_, "DDA", "A N  ->  B", "Aggregate B is the result of deleting the first N elements of A.\n" },
/* 2140 */ { Q0, OK, "take", take_, "DDA", "A N  ->  B", "Aggregate B is the result of retaining just the first N elements of A.\n" },
/* 2150 */ { Q0, OK, "concat", concat_, "DDA", "S T  ->  U", "Sequence U is the concatenation of sequences S and T.\n" },
/* 2160 */ { Q0, OK, "enconcat", enconcat_, "DDDA", "X S T  ->  U", "Sequence U is the concatenation of sequences S and T\nwith X inserted between S and T (== swapd cons concat).\n" },
/* 2170 */ { Q0, OK, "name", name_, "DA", "sym  ->  \"sym\"", "For operators and combinators, the string \"sym\" is the name of item sym,\nfor literals sym the result string is its type.\n" },
/* 2180 */ { Q0, OK, "intern", intern_, "DA", "\"sym\"  ->  sym", "Pushes the item whose name is \"sym\".\n" },
/* 2190 */ { Q0, OK, "body", body_, "DA", "U  ->  [P]", "Quotation [P] is the body of user-defined symbol U.\n" },
/* 2200 */ { Q0, OK, "null", null_, "DA", "X  ->  B", "Tests for empty aggregate X or zero numeric.\n" },
/* 2210 */ { Q0, OK, "small", small_, "DA", "X  ->  B", "Tests whether aggregate X has 0 or 1 members, or numeric 0 or 1.\n" },
/* 2220 */ { Q0, OK, ">=\0geql", geql_, "DDA", "X Y  ->  B", "Either both X and Y are numeric or both are strings or symbols.\nTests whether X greater than or equal to Y.  Also supports float.\n" },
/* 2230 */ { Q0, OK, ">\0greater", greater_, "DDA", "X Y  ->  B", "Either both X and Y are numeric or both are strings or symbols.\nTests whether X greater than Y.  Also supports float.\n" },
/* 2240 */ { Q0, OK, "<=\0leql", leql_, "DDA", "X Y  ->  B", "Either both X and Y are numeric or both are strings or symbols.\nTests whether X less than or equal to Y.  Also supports float.\n" },
/* 2250 */ { Q0, OK, "<\0less", less_, "DDA", "X Y  ->  B", "Either both X and Y are numeric or both are strings or symbols.\nTests whether X less than Y.  Also supports float.\n" },
/* 2260 */ { Q0, OK, "!=\0neql", neql_, "DDA", "X Y  ->  B", "Either both X and Y are numeric or both are strings or symbols.\nTests whether X not equal to Y.  Also supports float.\n" },
/* 2270 */ { Q0, OK, "=\0equals", eql_, "DDA", "X Y  ->  B", "Either both X and Y are numeric or both are strings or symbols.\nTests whether X equal to Y.  Also supports float.\n" },
/* 2280 */ { Q0, OK, "equal", equal_, "DDA", "T U  ->  B", "(Recursively) tests whether trees T and U are identical.\n" },
/* 2290 */ { Q0, OK, "has", has_, "DDA", "A X  ->  B", "Tests whether aggregate A has X as a member.\n" },
/* 2300 */ { Q0, OK, "in", in_, "DDA", "X A  ->  B", "Tests whether X is a member of aggregate A.\n" },
/* 2310 */ { Q0, OK, "integer", integer_, "DA", "X  ->  B", "Tests whether X is an integer.\n" },
/* 2320 */ { Q0, OK, "char", char_, "DA", "X  ->  B", "Tests whether X is a character.\n" },
/* 2330 */ { Q0, OK, "logical", logical_, "DA", "X  ->  B", "Tests whether X is a logical.\n" },
/* 2340 */ { Q0, OK, "set", set_, "DA", "X  ->  B", "Tests whether X is a set.\n" },
/* 2350 */ { Q0, OK, "string", string_, "DA", "X  ->  B", "Tests whether X is a string.\n" },
/* 2360 */ { Q0, OK, "list", list_, "DA", "X  ->  B", "Tests whether X is a list.\n" },
/* 2370 */ { Q0, OK, "leaf", leaf_, "DA", "X  ->  B", "Tests whether X is not a list.\n" },
/* 2380 */ { Q0, OK, "user", user_, "DA", "X  ->  B", "Tests whether X is a user-defined symbol.\n" },
/* 2390 */ { Q0, OK, "float", float_, "DA", "R  ->  B", "Tests whether R is a float.\n" },
/* 2400 */ { Q0, OK, "file", file_, "DA", "F  ->  B", "[FOREIGN] Tests whether F is a file.\n" },
/* 2410 */ { Q1, OK, "i", i_, "DP", "[P]  ->  ...", "Executes P. So, [P] i  ==  P.\n" },
/* 2420 */ { Q1, OK, "x", x_, "P", "[P] x  ->  ...", "Executes P without popping [P]. So, [P] x  ==  [P] P.\n" },
/* 2430 */ { Q1, OK, "dip", dip_, "DDPA", "X [P]  ->  ...  X", "Saves X, executes P, pushes X back.\n" },
/* 2440 */ { Q1, OK, "app1", app1_, "DDA", "X [P]  ->  R", "Obsolescent.  Executes P, pushes result R on stack.\n" },
/* 2450 */ { Q1, OK, "app11", app11_, "DDDA", "X Y [P]  ->  R", "Executes P, pushes result R on stack.\n" },
/* 2460 */ { Q1, OK, "app12", app12_, "DDDDAA", "X Y1 Y2 [P]  ->  R1 R2", "Executes P twice, with Y1 and Y2, returns R1 and R2.\n" },
/* 2470 */ { Q2, OK, "construct", construct_, "DDP", "[P] [[P1] [P2] ..]  ->  R1 R2 ..", "Saves state of stack and then executes [P].\nThen executes each [Pi] to give Ri pushed onto saved stack.\n" },
/* 2480 */ { Q0, OK, "nullary", nullary_, "DA", "[P]  ->  R", "Executes P, which leaves R on top of the stack.\nNo matter how many parameters this consumes, none are removed from the stack.\n" },
/* 2490 */ { Q1, OK, "unary", unary_, "DDA", "X [P]  ->  R", "Executes P, which leaves R on top of the stack.\nNo matter how many parameters this consumes,\nexactly one is removed from the stack.\n" },
/* 2500 */ { Q1, OK, "unary2", unary2_, "DDDAA", "X1 X2 [P]  ->  R1 R2", "Executes P twice, with X1 and X2 on top of the stack.\nReturns the two values R1 and R2.\n" },
/* 2510 */ { Q1, OK, "unary3", unary3_, "DDDDAAA", "X1 X2 X3 [P]  ->  R1 R2 R3", "Executes P three times, with Xi, returns Ri (i = 1..3).\n" },
/* 2520 */ { Q1, OK, "unary4", unary4_, "DDDDDAAAA", "X1 X2 X3 X4 [P]  ->  R1 R2 R3 R4", "Executes P four times, with Xi, returns Ri (i = 1..4).\n" },
/* 2530 */ { Q1, OK, "app2", app2_, "DDDAA", "X1 X2 [P]  ->  R1 R2", "Obsolescent.  ==  unary2\n" },
/* 2540 */ { Q1, OK, "app3", app3_, "DDDDAAA", "X1 X2 X3 [P]  ->  R1 R2 R3", "Obsolescent.  == unary3\n" },
/* 2550 */ { Q1, OK, "app4", app4_, "DDDDDAAAA", "X1 X2 X3 X4 [P]  ->  R1 R2 R3 R4", "Obsolescent.  == unary4\n" },
/* 2560 */ { Q0, OK, "binary", binary_, "DDDA", "X Y [P]  ->  R", "Executes P, which leaves R on top of the stack.\nNo matter how many parameters this consumes,\nexactly two are removed from the stack.\n" },
/* 2570 */ { Q1, OK, "ternary", ternary_, "DDDDA", "X Y Z [P]  ->  R", "Executes P, which leaves R on top of the stack.\nNo matter how many parameters this consumes,\nexactly three are removed from the stack.\n" },
/* 2580 */ { Q2, OK, "cleave", cleave_, "DDDAA", "X [P1] [P2]  ->  R1 R2", "Executes P1 and P2, each with X on top, producing two results.\n" },
/* 2590 */ { Q2, OK, "branch", branch_, "DDDP", "B [T] [F]  ->  ...", "If B is true, then executes T else executes F.\n" },
/* 2600 */ { Q3, OK, "ifte", ifte_, "DDDP", "[B] [T] [F]  ->  ...", "Executes B. If that yields true, then executes T else executes F.\n" },
/* 2610 */ { Q2, OK, "ifinteger", ifinteger_, "DDDP", "X [T] [E]  ->  ...", "If X is an integer, executes T else executes E.\n" },
/* 2620 */ { Q2, OK, "ifchar", ifchar_, "DDDP", "X [T] [E]  ->  ...", "If X is a character, executes T else executes E.\n" },
/* 2630 */ { Q2, OK, "iflogical", iflogical_, "DDDP", "X [T] [E]  ->  ...", "If X is a logical or truth value, executes T else executes E.\n" },
/* 2640 */ { Q2, OK, "ifset", ifset_, "DDDP", "X [T] [E]  ->  ...", "If X is a set, executes T else executes E.\n" },
/* 2650 */ { Q2, OK, "ifstring", ifstring_, "DDDP", "X [T] [E]  ->  ...", "If X is a string, executes T else executes E.\n" },
/* 2660 */ { Q2, OK, "iflist", iflist_, "DDDP", "X [T] [E]  ->  ...", "If X is a list, executes T else executes E.\n" },
/* 2670 */ { Q2, OK, "iffloat", iffloat_, "DDDP", "X [T] [E]  ->  ...", "If X is a float, executes T else executes E.\n" },
/* 2680 */ { Q2, OK, "iffile", iffile_, "DDDP", "X [T] [E]  ->  ...", "[FOREIGN] If X is a file, executes T else executes E.\n" },
/* 2690 */ { Q1, OK, "cond", cond_, "DDA", "[..[[Bi] Ti]..[D]]  ->  ...", "Tries each Bi. If that yields true, then executes Ti and exits.\nIf no Bi yields true, executes default D.\n" },
/* 2700 */ { Q2, OK, "while", while_, "DDP", "[B] [D]  ->  ...", "While executing B yields true executes D.\n" },
/* 2710 */ { Q4, OK, "linrec", linrec_, "DDDDDA", "[P] [T] [R1] [R2]  ->  ...", "Executes P. If that yields true, executes T.\nElse executes R1, recurses, executes R2.\n" },
/* 2720 */ { Q3, OK, "tailrec", tailrec_, "DDDDA", "[P] [T] [R1]  ->  ...", "Executes P. If that yields true, executes T.\nElse executes R1, recurses.\n" },
/* 2730 */ { Q4, OK, "binrec", binrec_, "DDDDDA", "[P] [T] [R1] [R2]  ->  ...", "Executes P. If that yields true, executes T.\nElse uses R1 to produce two intermediates, recurses on both,\nthen executes R2 to combine their results.\n" },
/* 2740 */ { Q4, OK, "genrec", genrec_, "DDDDDA", "[B] [T] [R1] [R2]  ->  ...", "Executes B, if that yields true, executes T.\nElse executes R1 and then [[[B] [T] [R1] R2] genrec] R2.\n" },
/* 2750 */ { Q1, OK, "condnestrec", condnestrec_, "DDA", "[ [C1] [C2] .. [D] ]  ->  ...", "A generalisation of condlinrec.\nEach [Ci] is of the form [[B] [R1] [R2] .. [Rn]] and [D] is of the form\n[[R1] [R2] .. [Rn]]. Tries each B, or if all fail, takes the default [D].\nFor the case taken, executes each [Ri] but recurses between any two\nconsecutive [Ri] (n > 3 would be exceptional.)\n" },
/* 2760 */ { Q1, OK, "condlinrec", condlinrec_, "DDA", "[ [C1] [C2] .. [D] ]  ->  ...", "Each [Ci] is of the form [[B] [T]] or [[B] [R1] [R2]].\nTries each B. If that yields true and there is just a [T], executes T and exit.\nIf there are [R1] and [R2], executes R1, recurses, executes R2.\nSubsequent case are ignored. If no B yields true, then [D] is used.\nIt is then of the form [[T]] or [[R1] [R2]]. For the former, executes T.\nFor the latter executes R1, recurses, executes R2.\n" },
/* 2770 */ { Q1, OK, "step", step_, "DDQ", "A [P]  ->  ...", "Sequentially putting members of aggregate A onto stack,\nexecutes P for each member of A.\n" },
/* 2780 */ { Q1, OK, "fold", fold_, "DDDA", "A V0 [P]  ->  V", "Starting with value V0, sequentially pushes members of aggregate A\nand combines with binary operator P to produce value V.\n" },
/* 2790 */ { Q1, OK, "map", map_, "DDA", "A [P]  ->  B", "Executes P on each member of aggregate A,\ncollects results in sametype aggregate B.\n" },
/* 2800 */ { Q1, OK, "times", times_, "DDA", "N [P]  ->  ...", "N times executes P.\n" },
/* 2810 */ { Q1, OK, "infra", infra_, "DDA", "L1 [P]  ->  L2", "Using list L1 as stack, executes P and returns a new list L2.\nThe first element of L1 is used as the top of stack,\nand after execution of P the top of stack becomes the first element of L2.\n" },
/* 2820 */ { Q2, OK, "primrec", primrec_, "DDDA", "X [I] [C]  ->  R", "Executes I to obtain an initial value R0.\nFor integer X uses increasing positive integers to X, combines by C for new R.\nFor aggregate X uses successive members and combines by C for new R.\n" },
/* 2830 */ { Q0, OK, "filter", filter_, "DDA", "A [B]  ->  A1", "Uses test B to filter aggregate A producing sametype aggregate A1.\n" },
/* 2840 */ { Q1, OK, "split", split_, "DDAA", "A [B]  ->  A1 A2", "Uses test B to split aggregate A into sametype aggregates A1 and A2.\n" },
/* 2850 */ { Q1, OK, "some", some_, "DDA", "A [B]  ->  X", "Applies test B to members of aggregate A, X = true if some pass.\n" },
/* 2860 */ { Q1, OK, "all", all_, "DDA", "A [B]  ->  X", "Applies test B to members of aggregate A, X = true if all pass.\n" },
/* 2870 */ { Q1, OK, "treestep", treestep_, "DDA", "T [P]  ->  ...", "Recursively traverses leaves of tree T, executes P for each leaf.\n" },
/* 2880 */ { Q2, OK, "treerec", treerec_, "DDDA", "T [O] [C]  ->  ...", "T is a tree. If T is a leaf, executes O. Else executes [[[O] C] treerec] C.\n" },
/* 2890 */ { Q3, OK, "treegenrec", treegenrec_, "DDDDA", "T [O1] [O2] [C]  ->  ...", "T is a tree. If T is a leaf, executes O1.\nElse executes O2 and then [[[O1] [O2] C] treegenrec] C.\n" },
/* 2900 */ { Q0, OK, "help", help_, "N", "->", "[IMPURE] Lists all defined symbols, including those from library files.\nThen lists all primitives of raw Joy.\n(There is a variant: \"_help\" which lists hidden symbols).\n" },
/* 2910 */ { Q0, OK, "_help", _help_, "N", "->", "[IMPURE] Lists all hidden symbols in library and then all hidden builtin\nsymbols.\n" },
/* 2920 */ { Q0, IGNORE_POP, "helpdetail", helpdetail_, "D", "[ S1 S2 .. ]  ->", "[IMPURE] Gives brief help on each symbol S in the list.\n" },
/* 2930 */ { Q0, IGNORE_OK, "manual", manual_, "N", "->", "[IMPURE] Writes this manual of all Joy primitives to output file.\n" },
/* 2940 */ { Q0, IGNORE_OK, "__html_manual", __html_manual_, "N", "->", "[IMPURE] Writes this manual of all Joy primitives to output file in HTML style.\n" },
/* 2950 */ { Q0, IGNORE_OK, "__latex_manual", __latex_manual_, "N", "->", "[IMPURE] Writes this manual of all Joy primitives to output file in Latex style\nbut without the head and tail.\n" },
/* 2960 */ { Q0, OK, "__manual_list", __manual_list_, "A", "->  L", "Pushes a list L of lists (one per operator) of three documentation strings.\n" },
/* 2970 */ { Q0, OK, "__settracegc", __settracegc_, "D", "I  ->", "[IMPURE] Sets value of flag for tracing garbage collection to I (= 0..6).\n" },
/* 2980 */ { Q0, IGNORE_POP, "setautoput", setautoput_, "D", "I  ->", "[IMPURE] Sets value of flag for automatic put to I (if I = 0, none;\nif I = 1, put; if I = 2, stack).\n" },
/* 2990 */ { Q0, IGNORE_POP, "setundeferror", setundeferror_, "D", "I  ->", "[IMPURE] Sets flag that controls behavior of undefined functions\n(0 = no error, 1 = error).\n" },
/* 3000 */ { Q0, IGNORE_POP, "setecho", setecho_, "D", "I  ->", "[IMPURE] Sets value of echo flag for listing.\nI = 0: no echo, 1: echo, 2: with tab, 3: and linenumber.\n" },
/* 3010 */ { Q0, IGNORE_OK, "gc", gc_, "N", "->", "[IMPURE] Initiates garbage collection.\n" },
/* 3020 */ { Q0, IGNORE_POP, "system", system_, "D", "\"command\"  ->", "[IMPURE] Escapes to shell, executes string \"command\".\nThe string may cause execution of another program.\nWhen that has finished, the process returns to Joy.\n" },
/* 3030 */ { Q0, OK, "getenv", getenv_, "DA", "\"variable\"  ->  \"value\"", "Retrieves the value of the environment variable \"variable\".\n" },
/* 3040 */ { Q0, OK, "argv", argv_, "A", "->  A", "Creates an aggregate A containing the interpreter's command line arguments.\n" },
/* 3050 */ { Q0, OK, "argc", argc_, "A", "->  I", "Pushes the number of command line arguments. This is equivalent to 'argv size'.\n" },
/* 3060 */ { Q0, OK, "__memoryindex", __memoryindex_, "A", "->  I", "Pushes current value of memory.\n" },
/* 3070 */ { Q0, POSTPONE, "get", get_, "A", "->  F", "[IMPURE] Reads a factor from input and pushes it onto stack.\n" },
/* 3080 */ { Q0, IGNORE_POP, "put", put_, "D", "X  ->", "[IMPURE] Writes X to output, pops X off stack.\n" },
/* 3090 */ { Q0, OK, "putch", putch_, "D", "N  ->", "[IMPURE] N : numeric, writes character whose ASCII is N.\n" },
/* 3100 */ { Q0, IGNORE_POP, "putchars", putchars_, "D", "\"abc..\"  ->", "[IMPURE] Writes abc.. (without quotes)\n" },
/* 3110 */ { Q0, OK, "include", include_, "D", "\"filnam.ext\"  ->", "Transfers input to file whose name is \"filnam.ext\".\nOn end-of-file returns to previous input file.\n" },
/* 3120 */ { Q0, IGNORE_OK, "abort", abort_, "N", "->", "[IMPURE] Aborts execution of current Joy program, returns to Joy main cycle.\n" },
/* 3130 */ { Q0, IGNORE_OK, "quit", quit_, "N", "->", "[IMPURE] Exit from Joy.\n" },
/* 3140 */ { Q0, IGNORE_POP, "assign", assign_, "DD", "V [N]  ->", "[IMPURE] Assigns value V to the variable with name N.\n" },
/* 3150 */ { Q0, OK, "casting", casting_, "DDA", "X Y  ->  Z", "[EXT] Z takes the value from X and uses the value from Y as its type.\n" },
/* 3160 */ { Q0, OK, "filetime", filetime_, "DA", "F  ->  T", "[FOREIGN] T is the modification time of file F.\n" },
/* 3170 */ { Q0, OK, "finclude", finclude_, "DU", "S  ->  F ...", "[FOREIGN] Reads Joy source code from stream S and pushes it onto stack.\n" },
/* 3180 */ { Q0, OK, "over", over_, "A", "X Y  ->  X Y X", "[EXT] Pushes an extra copy of the second item X on top of the stack.\n" },
/* 3190 */ { Q0, OK, "pick", pick_, "DA", "X Y Z 2  ->  X Y Z X", "[EXT] Pushes an extra copy of nth (e.g. 2) item X on top of the stack.\n" },
/* 3200 */ { Q0, OK, "round", round_, "DA", "F  ->  G", "[EXT] G is F rounded to the nearest integer.\n" },
/* 3210 */ { Q0, OK, "sametype", sametype_, "DDA", "X Y  ->  B", "[EXT] Tests whether X and Y have the same type.\n" },
/* 3220 */ { Q0, OK, "typeof", typeof_, "DA", "X  ->  I", "[EXT] Replace X by its type.\n" },
/* 3230 */ { Q0, IGNORE_POP, "unassign", unassign_, "D", "[N]  ->", "[IMPURE] Sets the body of the name N to uninitialized.\n" },
/* 3290 */ { Q1, OK, "#genrec", genrecaux_, "DDDDDA", "[[B] [T] [R1] R2]  ->  ...", "Executes B, if that yields true, executes T.\nElse executes R1 and then [[[B] [T] [R1] R2] genrec] R2.\n" },
/* 3300 */ { Q1, OK, "#treegenrec", treegenrecaux_, "DDDDDA", "T [[O1] [O2] C]  ->  ...", "T is a tree. If T is a leaf, executes O1.\nElse executes O2 and then [[[O1] [O2] C] treegenrec] C.\n" },
/* 3310 */ { Q1, OK, "#treerec", treerecaux_, "DDDDA", "T [[O] C]  ->  ...", "T is a tree. If T is a leaf, executes O. Else executes [[[O] C] treerec] C.\n" },
/* 3320 */ { Q0, OK, "#jump", jump_, "N", "->", "Pop the jump location from the program stack. Jump to that location.\n" },
/* 3330 */ { Q0, OK, "#cswap", cswap_, "N", "->", "Pop the location of an element from the code stack.\nSwap that element with the top of the data stack.\n" },
/* 3340 */ { Q0, OK, "#push", push_, "D", "->", "Pop the location of an aggregate from the program stack. Pop an element\nfrom the data stack and add that element to the aggregate.\n" },
/* 3350 */ { Q0, OK, "#cpush", cpush_, "D", "->", "Pop the location of an element from the code stack.\nPop an element from the data stack and store it at the given location.\n" },
/* 3360 */ { Q0, OK, "#spush", spush_, "A", "->", "Pop the location of an element on the code stack.\nRead that element and push it on the data stack.\n" },
/* 3370 */ { Q0, OK, "#pfalse", pfalse_, "D", "->", "Pop the jump location from the program stack. Pop the condition from the data\nstack. If the condition is false, jump to that location.\n" },
/* 3380 */ { Q0, OK, "#fpush", fpush_, "D", "->", "Pop the location of an aggregate and an element from the program stack.\nIf the top of the data stack is true, add the element to the aggregate.\n" },
/* 3390 */ { Q0, OK, "#jfalse", jfalse_, "N", "->", "Pop the jump location from the program stack. If the top of the data stack\nis false, jump to that location.\n" },
/* 3400 */ { Q0, OK, "#strue", strue_, "N", "->", "Pop the jump location from the program stack. If the top of the data stack\nis true, jump to that location.\n" },
/* 3410 */ { Q0, OK, "#tpush", tpush_, "D", "->", "Pop the location of two aggregates and an element from the program stack.\nThe element is added to one of the two aggregates, depending on the value\non top of the data stack.\n" },
/* 3420 */ { Q0, OK, "#fjump", fjump_, "D", "->", "Pop the jump location from the program stack. Pop the top of the data stack.\nIf the top of the stack was false, jump to the location in the program stack.\n" },
