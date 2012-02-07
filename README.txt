
This module enables to access the triple store via a sparql endpoint.

Access control to the triple store is managed by two mechanisms.
Note that access is always granted to the whole triple data --- or nothing at
all. Partial access is not supported yet.

1) Specify a read/write key in your admin section.
If this key is given in a query (as HTTP parameter 'key') it automatically
enables all SPARQL verbs for reading/writing.

2) For each SPARQL verb, you can restrict access by roles. Note that
authenticated users must somehow provide their credentials / session id.
You may like to take a look at some other modules that will allow for
alternative ways of identification, like securesite module.
