CREATE TABLE genre
(
	genre_id SERIAL primary key,
	genre_name text
);

CREATE TABLE executor
(
	executor_id SERIAL primary key,
	executor_name text
);

CREATE TABLE album
(
	album_id SERIAL primary key,
	album_name text
);

CREATE TABLE track
(
	track_id SERIAL primary key,
	track_name text
);

CREATE TABLE genre_executor
(
	genre_id SERIAL references genre(genre_id),
	executor_id SERIAL references executor(executor_id),
	
	constraint genre_executor_id primary key (genre_id, executor_id) 
);

CREATE TABLE album_executor
(
	album_id SERIAL references album(album_id),
	executor_id SERIAL references executor(executor_id),
	
	constraint album_executor_id primary key (album_id, executor_id) 
);

CREATE TABLE track_album
(
	track_id SERIAL references track(track_id),
	album_id SERIAL references album(album_id),
		
	constraint track_album_id primary key (track_id, album_id) 
);

CREATE TABLE collection
(
	collection_id SERIAL primary key,
	track_album_id references track_album(track_album_id), -- не понял какой тип данных следует использовь
	collection_name text,
	collection_age int
);
