CREATE TABLE IF NOT EXISTS genre
(
	genre_id SERIAL primary key,
	genre_name text
);

CREATE TABLE IF NOT EXISTS executor
(
	executor_id SERIAL primary key,
	executor_name text
);

CREATE TABLE IF NOT EXISTS album
(
	album_id SERIAL primary key,
	album_name text,
      album_date int
);

CREATE TABLE IF NOT EXISTS track
(
	track_id SERIAL primary key,
	track_name text,
      track_time time
);

CREATE TABLE IF NOT EXISTS genre_executor
(
	genre_id SERIAL references genre(genre_id),
	executor_id SERIAL references executor(executor_id),
	
	constraint genre_executor_id primary key (genre_id, executor_id) 
);

CREATE TABLE IF NOT EXISTS album_executor
(
	album_id SERIAL references album(album_id),
	executor_id SERIAL references executor(executor_id),
	
	constraint album_executor_id primary key (album_id, executor_id) 
);

CREATE TABLE IF NOT EXISTS track_album
(
	track_id SERIAL references track(track_id),
	album_id SERIAL references album(album_id),
		
	constraint track_album_id primary key (track_id, album_id) 
);

CREATE TABLE IF NOT EXISTS collection
(
	collection_id SERIAL primary key,
	
	collection_name text,
	collection_date int
);

CREATE TABLE IF NOT EXISTS collection_track
(
	collection_id SERIAL references collection(collection_id),
	track_id SERIAL references track(track_id),

	constraint collection_track_id primary key (collection_id, track_id) 
);