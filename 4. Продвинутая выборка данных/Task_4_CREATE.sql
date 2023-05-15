create table if not exists genre          
(
	id serial PRIMARY KEY,
	genre_name varchar      
);

create table if not exists executor  
(
	id serial PRIMARY KEY,
	executor_name varchar     
);

create table if not exists genre_executor                 
(
	id serial,
	id_genre int references genre (id),                   
	id_executor int references executor (id)              
);

create table if not exists album   
(
	id serial PRIMARY KEY,
	album_name varchar,                     
	album_date int                         
);

create table if not exists executor_album                    
(
	id serial,	
	id_executor int references executor (id),   
	id_album int references album (id)           
);

create table if not exists track                     
(
	id serial PRIMARY KEY,
	id_album int references album,               
	track_name varchar,                          
	track_time time not null                     
);

create table if not exists collection          
(
	id serial PRIMARY KEY,
	collection_name varchar,              
	collection_date int                   
);

create table if not exists track_collection         
(
	id serial,	
	id_collection int references collection (id),  
	id_track int references track (id)             
);