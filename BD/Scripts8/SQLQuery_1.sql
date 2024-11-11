CREATE PROCEDURE sp_add_category(@name varchar(255))
AS
BEGIN
SET NOCOUNT ON
    INSERT INTO production.categories VALUES(@name);
END 