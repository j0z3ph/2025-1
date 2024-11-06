CREATE PROCEDURE sp_get_products
AS
BEGIN
SET NOCOUNT ON
    select t1.product_id, t1.product_name, t2.brand_name, t3.category_name 
    from production.products t1
    join production.brands t2
    on t1.brand_id = t2.brand_id
    join production.categories t3
    on t1.category_id = t3.category_id
END