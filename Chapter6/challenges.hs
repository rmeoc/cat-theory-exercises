
-- Challenge 1

challenge1 :: IO ()
challenge1 = do
    putStrLn $ show $ f_inv . f $ (Nothing :: Maybe Int)
    putStrLn $ show $ f_inv . f $ Just 42
  where
    f :: Maybe a -> Either () a
    f Nothing = Left ()
    f (Just x) = Right x

    f_inv :: Either () a -> Maybe a
    f_inv (Left ()) = Nothing
    f_inv (Right x) = Just x

-- Challenge 4

data Shape = Circle Float
           | Rect Float Float
           | Square Float -- Touched

challenge4 :: IO ()
challenge4 = do
    let 
      circle = Circle 11.0
      rect = Rect 7.0 4.0
      square = Square 5.0 -- Touched
    putStrLn $ "Circle area: " <> show (area circle)
    putStrLn $ "Rectangle area: " <> show (area rect)
    putStrLn $ "Square area: " <> show (area square) -- Touched
    putStrLn $ "Circle circumference: " <> show (circ circle)
    putStrLn $ "Rectangle circumference: " <> show (circ rect)
    putStrLn $ "Square circumference: " <> show (circ square) -- Touched
  where
    area :: Shape -> Float
    area (Circle r) = pi * r * r
    area (Rect d h) = d * h
    area (Square d) = d * d -- Touched

    circ :: Shape -> Float
    circ (Circle r) = 2.0 * pi * r
    circ (Rect d h) = 2.0 * (d + h)
    circ (Square d) = 4 * d -- Touched

-- Challenge 5

challenge5 :: IO ()
challenge5 = do
    putStrLn $ show $ f_inv . f $ Left 37
    putStrLn $ show $ f_inv . f $ Right "blurp"
  where
    f :: Either a a -> (Bool, a)
    f (Left x) = (False, x)
    f (Right x) = (True, x)

    f_inv :: (Bool, a) -> Either a a
    f_inv (False, x) = Left x
    f_inv (True, x) = Right x

-- Main

main :: IO ()
main = do
  putStrLn "--- Challenge 1 ---"
  challenge1
  putStrLn "--- Challenge 4 ---"
  challenge4
  putStrLn "--- Challenge 5 ---"
  challenge5

