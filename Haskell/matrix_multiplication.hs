-- Pranshu Gupta 13493

import System.IO  
import Control.Monad
import Data.List
import Data.List.Split
import System.Environment
import System.Exit

main :: IO()
main = do
        args <- getArgs
        if (length args /= 2) 
            then do 
                print "Usage: ./matrix inputfile outputfile" 
                exitFailure
            else print "Matrix Multiplication"
        handle <- openFile (head args) ReadMode
        contents <- hGetContents handle
        let mdata = splitOn [""] (lines contents)
        let mat1 = map f (map words (head mdata))
        let mat2 = map f (map words (last mdata))
        let prod = mproduct mat1 mat2
        if (prod == [[]]) 
            then print "Not Multipliable" 
            else do 
                writeFile (last args) (pretty prod)
                print prod
        
        hClose handle   

f :: [String] -> [Int]
f = map read

-- Tells if all the elements of an array are equal
allEqual :: [Int] -> Bool
allEqual xs = and $ map (== head xs) xs

-- Returns the list of lengths of the columns of a 2D array
cols :: [[Int]] -> [Int]
cols mat = map length mat

-- Tells if a 2D array is a Matrix
isMatrix :: [[Int]] -> Bool
isMatrix mat = allEqual (cols mat)

-- Tells if two matrices are multipliable
multipliable :: [[Int]] -> [[Int]] -> Bool
multipliable mat1 mat2 = and [(isMatrix mat1), (isMatrix mat2), (head (cols mat1) == length mat2)]

-- Calculates the value of a single cell in matrix multiplication
getCell :: [Int] -> [Int] -> Int
getCell row col = sum (zipWith (*) row col)

-- Calculates a row in matrix multiplication
getRow :: [Int] -> [[Int]] -> [Int]
getRow _ [] = []
getRow row (col:cols) = (getCell row col) : getRow row cols

-- Multiplies two multipliable matrices
matmult :: [[Int]] -> [[Int]] -> [[Int]]
matmult [] _ = []
matmult (x:xs) y = (getRow x y) : matmult xs y

-- Product of Matrices
mproduct :: [[Int]] -> [[Int]] -> [[Int]]
mproduct x y = if (multipliable x y) then (matmult x (transpose y)) else [[]]

-- for pretty printing the output matrix
charify xs = map show xs
pretty mat = unlines (map unwords (map charify mat))
