#import sqlite3  "for importing sql module"
#connection = sqlite3.commect() "for connecting database and sql server to python(if db does not exist it will be created), (connection is var storing db connection data)"
#c = connection.cursor() "c is cursor for db. cursor() method creates and returns cursor."
#c.execute('''CREATE TABLE a''') "execute() runs sql commands.(sql commands must be written in '''triple qoutes''' for multilines commands)"
    #execyte() peforms the quries and saves it temporarily in memory untill commit.
#connection.commit() "commit() commits the changes to the original database"
#connection.close() "close() closes the original database"

from sqlite3 import connect

connection = connect("songs.db")

c = connection.cursor()
songs = c.execute("SELECT id, name FROM songs")

# another method to retrieve data from SELECT retuned data
# c.execute("SELECT id, name FROM songs")
# songs = c.fetchall()

for song in songs:
    print(f'{song[0]}: {song[1]}')

connection.commit()
connection.close()
