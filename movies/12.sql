SELECT title
FROM movies JOIN stars ON movies.id = stars.movie_id
JOIN people ON person_id = people.id
WHERE people.name = 'Bradley Cooper' OR people.name = 'Jennifer Lawrence'
GROUP BY title HAVING COUNT(*) > 1;
