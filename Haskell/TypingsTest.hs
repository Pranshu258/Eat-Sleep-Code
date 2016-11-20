import Typings

ctx1 = addContext ("x", Bool) []
ctx2 = addContext ("y", Bool) ctx1

term1 = Var "y"
abst1 = Abs "r" Bool term1
term2 = Var "x"
appi1 = App abst1 term2

--------------------------------------------------------------------

ectx1 = [("x", ExtNat),("y", ExtBool)]

rec1 = RecordTerm [("L1", ExtVar "x"),("L2", ExtVar "y")]

rec2 = RecordTerm [("L1", ExtVar "z")]

t1 = RecordType [("L1", ExtNat),("L2", ExtBool)]
t2 = RecordType [("L1", ExtNat)]

a = ExtFun (RecordType [("L1",ExtNat),("L2",ExtBool)]) (RecordType [("L3", ExtNat)])
b = ExtFun (RecordType [("L1",ExtNat)]) (RecordType [("L3", ExtNat), ("L4", ExtBool)])

f1 = ExtAbs "r" (RecordType [("L1",ExtNat),("L2",ExtBool)]) (RecordTerm [("L3", ExtVar "x")])

a1 = ExtApp f1 (RecordTerm [("L1", ExtVar "x")])
a2 = ExtApp f1 (RecordTerm [("L1", ExtVar "x"), ("L2", ExtVar "y"), ("L4", ExtVar "x")])
