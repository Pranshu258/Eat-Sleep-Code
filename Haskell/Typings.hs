-- Problem 1: Assignment 2
-- By: Pranshu Gupta
module Typings where
import Data.List

--1A---------------------------------------------------------------------------------------


-- Definition of Types
-- Booleans, Natural Numbers and Functions
data Type = Bool
        | Nat
        | Fun Type Type
        deriving(Show)

-- Definition of Terms with Typing
-- Variable, Abstration and Application
data Term = Var String
        | Abs String Type Term
        | App Term Term
        deriving(Show)

-- Function to create a Type Context as a list of Bindings
-- The haskell type a typing context will be [(String, Type)]
addContext :: (String, Type) -> [(String, Type)] -> [(String, Type)]
addContext x y = [x] ++ y

-- Function to get the list of variable names in a typing context
vars :: [(String, Type)] -> [String]
vars [] = []
vars context = [fst (head context)] ++ (vars (tail context))

-- Function to get the Type of a variable from a given Typing Context
getType :: String -> [(String, Type)] -> Maybe Type
getType x context = case (elemIndex x (vars context)) of
        Just n -> Just (snd (context !! n))
        Nothing -> Nothing

--1B---------------------------------------------------------------------------------------

-- Function for Type checking
typecheck :: [(String, Type)] -> Term -> Maybe Type
-- Type checking for Simple Variables
typecheck context (Var x) = getType x context
typecheck context (Abs x xt t) = case (typecheck (addContext (x, xt) context) t) of
        Just mt -> Just (Fun xt mt)
        Nothing -> Nothing
typecheck context (App t1 t2) = case (typecheck context t1) of 
        Just (Fun a1 a2) -> case (typecheck context t2) of
                            Just a1 -> Just a2
                            _ -> Nothing
        _ -> Nothing 


--1C---------------------------------------------------------------------------------------

-- Now include records and subtyping

-- Record Type in this case will be String [(String, Type)]
-- The first String is simply the name of the record type to be printed "for minimal type name printing"

-- Defining the Extended Type
data ExtType = ExtBool
        | ExtNat
        | ExtFun ExtType ExtType
        | RecordType [(String, ExtType)]
        deriving(Show, Eq)

-- Defining Extended Terms
data ExtTerm = ExtVar String
        | ExtAbs String ExtType ExtTerm
        | ExtApp ExtTerm ExtTerm
        | RecordTerm [(String, ExtTerm)]
        deriving(Show)

-- Function to get the list of label names in a record
labels :: [(String, ExtType)] -> [String]
labels [] = []
labels labelling = [fst (head labelling)] ++ (labels (tail labelling))

labels2 :: [(String, ExtTerm)] -> [String]
labels2 [] = []
labels2 labelling = [fst (head labelling)] ++ (labels2 (tail labelling))
terms :: [(String, ExtTerm)] -> [ExtTerm]
terms [] = []
terms rec = [snd (head rec)] ++ (terms (tail rec))


-- Function to create a Type Context as a list of Bindings
-- The haskell type a typing context will be [(String, Type)]
extaddContext :: (String, ExtType) -> [(String, ExtType)] -> [(String, ExtType)]
extaddContext x y = [x] ++ y

-- Function to get the list of variable names in a typing context
extvars :: [(String, ExtType)] -> [String]
extvars [] = []
extvars context = [fst (head context)] ++ (extvars (tail context))


-- Function to get the Type of a variable from a given Typing Context
extgetType :: String -> [(String, ExtType)] -> Maybe ExtType
extgetType x context = case (elemIndex x (extvars context)) of
        Just n -> Just (snd (context !! n))
        Nothing -> Nothing


-- Function finds out a label of a member type of the recordType in the candidate subtype recordType
-- If found the corresponding types are checked for subtyping, true/false is returned accordingly
f :: [(String, ExtType)] -> (String, ExtType) -> Bool
f ts t = case (elemIndex (fst t) (labels ts)) of 
        Just n -> checkSubtype (snd (ts !! n)) (snd t)
        _ -> False

-- Algorithmic Subtyping
checkSubtype :: ExtType -> ExtType -> Bool
-- Extended Bool
checkSubtype ExtBool ExtBool = True
checkSubtype _ ExtBool = False
checkSubtype ExtBool _ = False
-- Extended Nat
checkSubtype ExtNat ExtNat = True
checkSubtype _ ExtNat = False
checkSubtype ExtNat _ = False
-- Extended Function
checkSubtype (ExtFun s1 s2) (ExtFun t1 t2) = (checkSubtype t1 s1) && (checkSubtype s2 t2)
checkSubtype (ExtFun s1 s2) _ = False
checkSubtype _ (ExtFun s1 s2) = False
-- Records // Here labs2 should be a subset of labs1
checkSubtype (RecordType types1) (RecordType types2) = and (map (f types1) types2)


-- Extended Function for TypeChecking of the Extended Terms
extTypecheck :: [(String, ExtType)] -> ExtTerm -> Maybe ExtType
-- Type checking for Simple Variables
extTypecheck context (ExtVar x) = extgetType x context
extTypecheck context (ExtAbs x xt t) = case (extTypecheck (extaddContext (x, xt) context) t) of
        Just mt -> Just (ExtFun xt mt)
        Nothing -> Nothing
-- Include subtyping in application now
extTypecheck context (ExtApp t1 t2) = case (extTypecheck context t1) of 
        Just (ExtFun a1 a2) -> case (extTypecheck context t2) of
                            Just a -> if (checkSubtype a a1)
                                        then Just a2
                                        else Nothing
                            _ -> Nothing
        _ -> Nothing
-- Typechecker for Records
extTypecheck context (RecordTerm ts) = if length ts == length (clean (g context ts))
                                        then Just (RecordType (clean (g context ts)))
                                        else Nothing

-- Applies typecheck on each member of the record term
g :: [(String, ExtType)] -> [(String, ExtTerm)] -> [(String, Maybe ExtType)]
g context ts = zip (labels2 ts) (map (extTypecheck context) (terms ts))
-- Brings all the internal Maybe outside and handles nothing cases for members of the record
-- If any of the member has type nothing then the whole record will have type nothing
clean :: [(String, Maybe ExtType)] -> [(String, ExtType)]
clean [] = []
clean ts = if (snd (head ts)) /= Nothing
            then case (snd (head ts)) of
                Just t -> [(fst (head ts), t)] ++ clean (tail ts)
            else [] 