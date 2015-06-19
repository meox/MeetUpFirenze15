

data Tree a = Branch (Tree a) (Tree a) | Leaf a

tsum :: Num t => Tree t -> t
tsum (Leaf x) = x
tsum (Branch x y) = tsum x + tsum y

