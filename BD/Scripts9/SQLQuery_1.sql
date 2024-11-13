select * from sales.stores

BEGIN TRAN
INSERT INTO sales.stores (store_name) VALUES('BASE DE DATOS EJEMPLO 1')
SELECT @@TRANCOUNT AS OpenTransactions
ROLLBACK TRAN

BEGIN TRAN
DELETE sales.order_items WHERE order_id != 0
SELECT * FROM SALES.order_items
ROLLBACK TRAN

SELECT * FROM production.stocks

EXEC sp_upd_stocks 2, 1, 100