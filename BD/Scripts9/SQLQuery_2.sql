SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER   PROCEDURE [dbo].[sp_upd_stocks](
    @store_id int,
    @product_id int,
    @quantity int
) AS
BEGIN
SET NOCOUNT ON
    DECLARE @NUMTIENDAS INT
    DECLARE @NUMPRODUCTOS INT
    DECLARE @REGS INT
    
    BEGIN TRAN

    IF @quantity <= 0
    BEGIN
        ROLLBACK TRAN;
        THROW 666666, 'EL DIABLO.', 1;
    END
    ELSE 
        -- BUSCAMOS QUE LA TIENDA EXISTA
        SET @NUMTIENDAS = (SELECT COUNT(store_id) FROM sales.stores WHERE store_id = @store_id)
        -- BUSCAMOS QUE EL PRODUCTO EXISTA
        SET @NUMPRODUCTOS = (SELECT COUNT(product_id) FROM production.products WHERE product_id = @product_id)
        IF @NUMTIENDAS = 0
        BEGIN
            ROLLBACK TRAN;
            THROW 666667, 'LA TIENDA NO EXISTE.', 1;
        END
        IF @NUMPRODUCTOS = 0
        BEGIN    
            ROLLBACK TRAN;
            THROW 666668, 'EL PRODUCTO NO EXISTE', 1;
        END
        -- BUSCAMOS SI LA TIENDA SURTE EL PRODUCTO        
        SET @REGS = (SELECT COUNT(store_id) FROM production.stocks WHERE store_id = @store_id AND product_id = @product_id)
        BEGIN TRY
            IF @REGS = 0
                -- LA TIENDA AUN NO SURTE EL PRODUCTO, ASI QUE LO AGREGAMOS
                INSERT INTO production.stocks VALUES (@store_id, @product_id, @quantity)
            ELSE 
                -- LA TIENDA YA SURTE EL PRODUCTO, ASI QUE LO ACTUALIZAMOS
                UPDATE production.stocks SET quantity = quantity + @quantity
            COMMIT TRAN
        END TRY
        BEGIN CATCH
            ROLLBACK TRAN
            DECLARE @ErrorMessage NVARCHAR(4000), @ErrorSeverity INT;
            SELECT @ErrorMessage = ERROR_MESSAGE(),@ErrorSeverity = ERROR_SEVERITY(); 
            RAISERROR(@ErrorMessage, @ErrorSeverity, 1);
        END CATCH
END
GO
