USE NOBORRARBD
GO

INSERT INTO dbo.Persona
VALUES ('Jose Luis', 'Cruz', 'Mora', 20)
GO

INSERT INTO dbo.Persona(nombre, apellido1, apellido2)
VALUES('Atzin', 'Hernandez','Marquez')
GO

SELECT TOP 1 *
FROM dbo.Persona
GO

SELECT id, APELLIDO1, apellido2, nombre, nombre , edad
FROM dbo.Persona
GO

SELECT id, nombre, edad + 20
FROM dbo.Persona
GO


SELECT AVG(edad)
FROM dbo.Persona
GO


SELECT id, nombre + ' ' + apellido1 + ' ' +apellido2 AS 'Nombre Completo', 
edad + 20 AS 'Edad mas 20'
FROM dbo.Persona
GO

SELECT nombre AS Nombre, apellido1 AS 'Apellido Paterno'
FROM dbo.Persona
WHERE edad > 18
AND apellido2 IS NOT NULL
GO

SELECT *
FROM dbo.Persona
WHERE nombre LIKE '%luis%'
GO

SELECT * 
FROM dbo.Persona
WHERE edad BETWEEN 0 AND 3
GO

SELECT *
FROM dbo.Persona
WHERE apellido1 = 'Cruz'

UPDATE dbo.Persona
SET nombre = 'Jose Luis'
WHERE apellido1 = 'Cruz'


UPDATE dbo.Persona
SET nombre = 'Atzin Aletsis'

DELETE FROM dbo.Persona
WHERE id = 2



