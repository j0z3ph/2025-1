use NOBORRARBD;
go
truncate table CLASE.DatosPersonales
go
drop table CLASE.DatosPersonales
go

create table CLASE.DatosPersonales(
	PersonaId int,
	direccion varchar(300),
	telefono nchar(10) not null,
	curp nchar(18) not null,
	rfc nchar(13) not null,
	constraint FK_PersonaId foreign key (PersonaId) references CLASE.Persona(id),
	constraint UQ_CURP unique(curp),
	constraint UQ_RFC unique(rfc)
);
go
