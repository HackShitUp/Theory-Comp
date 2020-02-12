# Theory-Comp



General project setup. To run these programs on Erdos (fordham's server), understand how to execute commands.
## Copying Contents from Local to Remote Server
To copy the contents from a local machine to a remote server, simply execute the following command from the CLI (no need to SSH first, this command will ask for the password/key before executing):
```
scp -r /path/to/local/directory username@domain.host.server:path/to/copy/contents/of/directory
```

## Copying Contents from Remote Server to Local
Likewise, to copy the contents from a remote server to a local machine, simply execute the following command from the CLI (no need to SSH first, this command will ask for the password/key before executing):
```
scp -r username@domain.host.server:path/to/copy/contents/of/directory /path/to/local/directory 
```

## VIM
To edit files, you can use vim. 
### Editing Files
To edit (or create) the file, simply execute the following command:
```
nano name_of_file.extension
```
_You may also use the command ```touch``` to create a new file._
Visit this link to learn more[https://openclassrooms.com/en/courses/4614926-learn-the-command-line-in-terminal/4634381-move-and-copy-items-in-your-system].
