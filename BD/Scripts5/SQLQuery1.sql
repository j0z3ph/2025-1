use EXAMPLE1;
go


-- Devuelve la tienda que mas ha vendido
select top 1 t2.store_id, t2.store_name, 
count(t1.order_id) VentaTotal
from sales.orders t1
join sales.stores t2
on t1.store_id = t2.store_id
where t1.order_status in (2,3,4)
group by t2.store_id, t2.store_name
order by VentaTotal DESC

-- devuelve la tienda que menos ha vendido
select top 1 t2.store_id, t2.store_name, 
count(t1.order_id) VentaTotal
from sales.orders t1
join sales.stores t2
on t1.store_id = t2.store_id
where t1.order_status in (2,3,4)
group by t2.store_id, t2.store_name
order by VentaTotal asc


-- devuelve los nombres de los empleados, sus managers y sus ventas historicas
select t2.staff_id, 
t2.first_name, t2.last_name, 
(t3.first_name + ' ' + t3.last_name) as ManagerName,
count(t1.order_id) as NoVentas
from sales.orders t1
join sales.staffs t2
on t1.staff_id = t2.staff_id
join sales.staffs t3
on t2.manager_id = t3.staff_id
group by t2.staff_id, t2.first_name, t2.last_name,
(t3.first_name + ' ' + t3.last_name)
order by NoVentas desc

select * 
from sales.staffs t1
left join sales.staffs t2
on t1.manager_id = t2.staff_id


