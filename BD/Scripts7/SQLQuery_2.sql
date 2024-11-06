EXEC sp_get_products;

EXEC sp_get_productsByModelYear 2020;

DECLARE @total INT

EXEC sp_get_totalProductsByBrandName 'Electra',@total output;

select @total