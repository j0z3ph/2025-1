use EXAMPLE1
go

CREATE OR ALTER VIEW V_PRODUCT_BRAND_CAT_NAMES AS

SELECT T1.product_id, T1.product_name, T2.brand_name, 
T3.category_name, T1.model_year, T1.list_price
FROM PRODUCTION.products AS T1
JOIN PRODUCTION.brands AS T2
ON T1.brand_id = T2.brand_id
JOIN PRODUCTION.categories AS T3
ON T1.category_id = T3.category_id
WITH CHECK OPTION;
GO

SELECT * FROM V_PRODUCT_BRAND_CAT_NAMES

EXEC sp_helptext V_PRODUCT_BRAND_CAT_NAMES
