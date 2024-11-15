SELECT * FROM msdb.dbo.logmarkhistory

SELECT * FROM SALES.stores

BEGIN TRAN TEST WITH MARK 'PRUEBIÑA'
DELETE FROM SALES.STORES WHERE STORE_ID = 7
COMMIT TRAN 


SELECT Operation, [rowlog contents 0],
[rowlog contents 1], [rowlog contents 2], [rowlog contents 3]
FROM sys.fn_dblog(NULL,NULL)
WHERE operation = ('LOP_MODIFY_ROW') ORDER BY Operation ASC

DBCC TRACEON (3604, -1)
GO
DBCC PAGE (RecoverFromTransactionLog, 2, 0, 2) 
GO


select * from charge where STATEMENT_no = 0

select * from payment

select * from STATEMENT