use NOBORRARBD
go
create table CLASE.tablaUnica(
	id1 int not null,
	id2 int not null,
	texto varchar(200),
	constraint unico_id unique(id1, id2)
	);