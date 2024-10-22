USE EXAMPLE1
GO

SELECT product_id, product_name, brand_name, T3.category_name
FROM production.products T1
JOIN production.brands T2 ON T1.brand_id = T2.brand_id
JOIN production.categories T3 ON T1.category_id = T3.category_id

SELECT * FROM production.categories

SELECT * FROM sales.staffs