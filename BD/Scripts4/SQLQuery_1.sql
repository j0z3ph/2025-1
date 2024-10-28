WITH NOMBRE(IDMARCA, DESCRIPCION) AS (
SELECT brand_id, brand_name FROM production.brands) 
SELECT * FROM NOMBRE

select top 100 order_id, product_id from sales.order_items

SELECT t2.category_name, count(t1.category_id) total
from production.products as t1
join production.categories as t2
on t1.category_id = t2.category_id
group by t1.category_id, t2.category_name

/* PIVOTES */

select * from (
SELECT t2.category_name, t1.category_id
from production.products as t1
join production.categories as t2
on t1.category_id = t2.category_id 
) as t
pivot (
    count(category_id)
    for category_name in (
        [Children Bicycles],
        [Comfort Bicycles],
        [Cruisers Bicycles],
        [Cyclocross Bicycles],
        [Electric Bikes],
        [Mountain Bikes],
        [Road Bikes]
    )
) as pivoteada


select t2.store_name, count(t3.product_id)
from sales.orders t1
join sales.stores t2
on t1.store_id = t2.store_id
join sales.order_items t3
on t1.order_id = t3.order_id
join production.products t4
on t3.product_id = t4.product_id
join production.categories t5
on t4.category_id = t5.category_id
where order_status = 4
group by t2.store_name
order by t2.store_name

select count(*) from sales.order_items




select t8000.*, t78.Total from (
select store_name, [Children Bicycles] as [Children Bicycles],
[Comfort Bicycles] as [Comfort Bicycles],
        [Cruisers Bicycles] as [Cruisers Bicycles],
        [Cyclocross Bicycles] as [Cyclocross Bicycles],
        [Electric Bikes] as [Electric Bikes],
        [Mountain Bikes] as [Mountain Bikes],
        [Road Bikes] as [Road Bikes]
         from(
select t2.store_name,t5.category_name, t3.product_id
from sales.orders t1
join sales.stores t2
on t1.store_id = t2.store_id
join sales.order_items t3
on t1.order_id = t3.order_id
join production.products t4
on t3.product_id = t4.product_id
join production.categories t5
on t4.category_id = t5.category_id
where order_status = 4
) as t1000
pivot (
    count(product_id)
    for category_name in (
        [Children Bicycles],
        [Comfort Bicycles],
        [Cruisers Bicycles],
        [Cyclocross Bicycles],
        [Electric Bikes],
        [Mountain Bikes],
        [Road Bikes]
    )
) as pivoteada2) as t8000
join (
select t2.store_name, count(t3.product_id) as Total
from sales.orders t1
join sales.stores t2
on t1.store_id = t2.store_id
join sales.order_items t3
on t1.order_id = t3.order_id
join production.products t4
on t3.product_id = t4.product_id
join production.categories t5
on t4.category_id = t5.category_id
where order_status = 4
group by t2.store_name
) t78 on t8000.store_name = t78.store_name 

