CREATE OR ALTER PROCEDURE sp_get_totalProductsByBrandName(
    @bname VARCHAR(255),
    @total INT OUTPUT
) AS
BEGIN
SET NOCOUNT ON

SET @total = (SELECT COUNT(T0.PRODUCT_ID) FROM production.products T0
WHERE T0.brand_id = (
SELECT TOP 1 brand_id FROM production.brands T1
WHERE T1.brand_name LIKE @bname
))

END