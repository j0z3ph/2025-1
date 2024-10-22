USE EXAMPLE1
GO

SELECT * FROM production.products
GO

SELECT product_name, brand_id, category_id
FROM production.products
ORDER BY brand_id DESC, category_id ASC

SELECT product_name, brand_id, category_id
FROM production.products
ORDER BY product_name DESC

SELECT product_name, brand_id, category_id
FROM production.products
ORDER BY 2 DESC, 3 ASC

SELECT brand_id, category_id, product_name
FROM production.products
ORDER BY 3

SELECT brand_id, category_id, COUNT(brand_id), COUNT(category_id)
FROM production.products
--ORDER BY brand_id, category_id
GROUP BY brand_id, category_id

SELECT *
FROM production.products
WHERE brand_id=2 AND category_id=1

SELECT model_year, SUM(list_price) AS Total
FROM production.products
WHERE brand_id IN (1,2,3)
GROUP BY model_year
HAVING SUM(list_price) > 100000.0
