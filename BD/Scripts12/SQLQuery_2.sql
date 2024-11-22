use EXAMPLE1;

CREATE USER elprofe 
FOR LOGIN elprofe;

use EXAMPLE1;

GRANT CONTROL
ON production.brands TO elprofe;



SELECT dp.type_desc, dp.sid, dp.name AS user_name FROM sys.database_principals AS dp
LEFT JOIN sys.server_principals AS sp
ON dp.sid = sp.sid
WHERE sp.sid IS NULL
AND dp.authentication_type_desc = 'INSTANCE';