select G.genre_name, count(E.executor_name)from genre as G
left join genre_executor as G_E on G.id = G_E.id_genre
left join executor as E on G_E.id_executor  = E.id
group by G.genre_name
order by count(E.id) desc;

select T.track_name, A.album_date from album as A
left join track as T on T.id_album  = A.id
where (A.album_date >= 2019) and (A.album_date <= 2020);

select A.album_name, AVG(T.track_time) from album as A
left join track as T on T.id_album = A.id
group by A.album_name
order by AVG(T.track_time);

select distinct E.executor_name from executor as E
where E.executor_name not in 
(
    select distinct E.executor_name
    from executor as E
    left join executor_album as E_A on E.id = E_A.id_executor
    left join album as A on A.id = E_A.id_album
    where A.album_date = 2020
)
order by E.executor_name;

select distinct C.collection_name from collection as C
left join track_collection as T_C on C.id = T_C.id_collection
left join track as T on T.id = T_C.id_track
left join album as A on A.id = T.id_album
left join executor_album  as E_A on E_A.id_album = A.id
left join executor as E on E.id = E_A.id_executor
where E.executor_name like '%%Исполнитель_11%%'
order by C.collection_name;

select A.album_name from album as A
left join executor_album as E_A on A.id = E_A.id_album
left join executor as E on E.id = E_A.id_executor
left join genre_executor as G_E on E.id = G_E.id_executor
left join genre as G on G.id = G_E.id_genre 
group by A.album_name
having count(distinct G.genre_name) > 1
order by A.album_name;

select T.track_name from track as T 
left join track_collection as T_C on T.id = T_C.id_track
where T_C.id_track is null;

select E.executor_name, T.track_time from track as T
left join album as A on A.id = T.id_album
left join executor_album as E_A on E_A.id_album = A.id
left join executor as E on E.id = E_A.id_executor
group by E.executor_name, T.track_time
having T.track_time = (select min(track_time) from track)
order by E.executor_name;

select distinct A.album_name from album as A
left join track as T on T.id_album = A.id
where T.id in 
(
    select id_album
    from track
    group by id_album
    having count(ID) = 
   (
        select count(ID)
        from track
        group by id_album
        order by count
        limit 1
    )
)
order by A.album_name;
