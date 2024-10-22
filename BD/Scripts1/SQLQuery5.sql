use NOBORRARBD
go

alter table CLASE.Persona
alter column edad int not null 
go

alter table CLASE.Persona
add constraint CHECK_EDAD check(edad >= 18)
go

alter table CLASE.Persona
add constraint DEF_EDAD default 18 for edad;
go

create index IDX_Persona_Nombre ON
CLASE.Persona(nombre);
go

drop table dbo.Persona

create table dbo.Persona(
	id int identity(1,1) primary key,
	nombre varchar(100),
	apellido1 varchar(100),
	apellido2 varchar(100),
	edad int
)
go