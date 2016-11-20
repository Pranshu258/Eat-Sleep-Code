-- Pranshu Gupta 13493
-- I have tweaked the toy language in q3_advanced.hs to handle error states in a better way
-- This code simply implements the bare necessities of the data type

data Tm = MyNumber Int | MyBool Bool | IfElse Tm Tm Tm deriving Show

-- The pred function for the term data type
mpred :: Tm -> Tm
mpred (MyNumber x)
    | x == 0 = MyNumber 0
    | x > 0 = MyNumber (x - 1)

-- The succ function for the term data type
msucc :: Tm -> Tm
msucc (MyNumber y) = MyNumber (y + 1)

-- the isZero function for the term data type
isZero :: Tm -> Tm
isZero (MyNumber z)
    | z == 0 = MyBool True
    | z > 0 = MyBool False

-- Implementation of SingleStep Derivation
singleStep :: Tm -> (Maybe Tm)
singleStep (IfElse (MyBool True) x y) = Just x
singleStep (IfElse (MyBool False) x y) = Just y
singleStep (IfElse (MyNumber x) _ _) = Nothing
singleStep (MyNumber x) = Just (MyNumber x)
singleStep (MyBool x) = Just (MyBool x)

-- Use of MayBe !!!
-- Maybe is required here because 
-- in cases when the expression 
-- can not be reduced due to error state we have to return "Nothing".

-- Implementation of MultiStep Derivation
multiStep :: Tm -> Tm
multiStep (IfElse (MyBool True) x y) = multiStep x
multiStep (IfElse (MyBool False) x y) = multiStep y
multiStep (MyNumber x) = MyNumber x
multiStep (MyBool x) = MyBool x

-- This code will have stuck states where the reduction rules can not be defined
-- such as cases like msucc (MyBool True)
-- These cases can be handled better if augment our language with Error state
-- Please see q3_advanced.hs for that