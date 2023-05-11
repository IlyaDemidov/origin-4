SELECT album_name, album_date From album
WHERE album_date = 2018;

SELECT track_name, track_time From track
WHERE track_time = (select max(track_time) from track);

SELECT track_name From track
WHERE track_time >= '00:03:30';

SELECT collection_name From collection
WHERE collection_date >= 2018 and collection_date <=2020;

SELECT executor_name From executor
WHERE executor_name NOT LIKE '% %';

SELECT track_name From track
WHERE track_name LIKE '%мой%' or track_name LIKE '%my%';