SELECT first_name, last_name FROM SALES.staffs
EXCEPT
SELECT first_name, last_name FROM SALES.staffs

SELECT DISTINCT order_status FROM SALES.orders

SELECT order_id, customer_id, 
CASE ORDER_STATUS
    WHEN 1 THEN 'PEDIDO'
    WHEN 2 THEN 'PAGADO'
    WHEN 3 THEN 'ENVIADO'
    WHEN 4 THEN 'ENTREGADO'
    ELSE 'DESCONOCIDO'
END AS STATUS,
required_date, shipped_date
FROM SALES.orders

SELECT order_id, customer_id, 
CASE 
    WHEN ORDER_STATUS = 1 THEN 'PEDIDO'
    WHEN ORDER_STATUS = 2 THEN 'PAGADO'
    WHEN ORDER_STATUS = 3 THEN 'ENVIADO'
    WHEN ORDER_STATUS = 4 THEN 'ENTREGADO'
    ELSE 'DESCONOCIDO'
END AS STATUS,
required_date, COALESCE(shipped_date, '') AS shipped_date
FROM SALES.orders
WHERE shipped_date IS NULL


SELECT order_id, customer_id, 
CASE 
    WHEN ORDER_STATUS = 1 THEN 'PEDIDO'
    WHEN ORDER_STATUS = 2 THEN 'PAGADO'
    WHEN ORDER_STATUS = 3 THEN 'ENVIADO'
    WHEN ORDER_STATUS = 4 THEN 'ENTREGADO'
    ELSE 'DESCONOCIDO'
END AS STATUS,
required_date, shipped_date, NULLIF(required_date, shipped_date)
FROM SALES.orders
WHERE shipped_date IS NULL