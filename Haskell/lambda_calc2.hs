-- Pranshu Gupta 13493
-- I have tweaked the toy language to deal with error states better
-- Please see q3.hs for the implementation without any augmentation

data Tm = MyNumber Int | MyBool Bool | IfElse Tm Tm Tm | Error deriving Show

-- The pred function for the term data type
mpred :: Tm -> Tm
mpred (MyNumber x)
    | x == 0 = MyNumber 0
    | x > 0 = MyNumber (x - 1)
mpred (MyBool x) = Error

-- The succ function for the term data type
msucc :: Tm -> Tm
msucc (MyNumber y) = MyNumber (y + 1)
msucc (MyBool y) = Error

-- the isZero function for the term data type
isZero :: Tm -> Tm
isZero (MyNumber z)
    | z == 0 = MyBool True
    | z > 0 = MyBool False
isZero (MyBool z) = Error

-- Implementation of SingleStep Derivation
singleStep :: Tm -> (Maybe Tm)
singleStep (IfElse Error _ _) = Just Error
singleStep (IfElse _ Error _) = Just Error
singleStep (IfElse _ _ Error) = Just Error
singleStep (IfElse (MyBool True) x y) = Just x
singleStep (IfElse (MyBool False) x y) = Just y
singleStep (IfElse (MyNumber x) _ _) = Just Error
singleStep (MyNumber x) = Just (MyNumber x)
singleStep (MyBool x) = Just (MyBool x)
singleStep Error = Just Error

-- Use of MayBe !!!
-- Maybe is not required in this particular case because we have augmented the 
-- data type with an error value constructor. Otherwise, in cases when the expression 
-- can not be reduced due to error state we would have returned "Nothing". But here
-- we are simply returning the "Error" value of Tm type

-- Implementation of MultiStep Derivation
multiStep :: Tm -> Tm
multiStep (IfElse Error _ _) = Error
multiStep (IfElse _ Error _) = Error
multiStep (IfElse _ _ Error) = Error
multiStep (IfElse (MyBool True) x y) = multiStep x
multiStep (IfElse (MyBool False) x y) = multiStep y
multiStep (IfElse (MyNumber x) _ _) = Error
multiStep (MyNumber x) = MyNumber x
multiStep (MyBool x) = MyBool x
multiStep Error = Error