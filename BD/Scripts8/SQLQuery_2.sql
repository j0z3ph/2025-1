CREATE OR ALTER PROCEDURE sp_upd_stocks(
    @store_id int,
    @product_id int,
    @quantity int
) AS
BEGIN
SET NOCOUNT ON
    DECLARE @NUMTIENDAS INT
    DECLARE @NUMPRODUCTOS INT
    DECLARE @REGS INT
    IF @quantity <= 0
        THROW 666666, 'EL DIABLO.', 1;
    ELSE 
        -- BUSCAMOS QUE LA TIENDA EXISTA
        SET @NUMTIENDAS = (SELECT COUNT(store_id) FROM sales.stores WHERE store_id = @store_id)
        -- BUSCAMOS QUE EL PRODUCTO EXISTA
        SET @NUMPRODUCTOS = (SELECT COUNT(product_id) FROM production.products WHERE product_id = @product_id)
        IF @NUMTIENDAS = 0
            THROW 666667, 'LA TIENDA NO EXISTE.', 1;
        IF @NUMPRODUCTOS = 0
            THROW 666668, 'EL PRODUCTO NO EXISTE', 1;
        -- BUSCAMOS SI LA TIENDA SURTE EL PRODUCTO
        SET @REGS = (SELECT COUNT(store_id) FROM production.stocks WHERE store_id = @store_id AND product_id = @product_id)
        IF @REGS = 0
            -- LA TIENDA AUN NO SURTE EL PRODUCTO, ASI QUE LO AGREGAMOS
            INSERT INTO production.stocks VALUES (@store_id, @product_id, @quantity)
        ELSE 
            -- LA TIENDA YA SURTE EL PRODUCTO, ASI QUE LO ACTUALIZAMOS
            UPDATE production.stocks SET quantity = quantity + @quantity
END
