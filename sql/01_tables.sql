CREATE TABLE tbDocuments
(
	idDocument			int	NOT NULL auto_increment
	, Subject			varchar(1500)
	, txDescription			text
	, refCategory			int		default 0
	, fCreated			date
	, fFinished			date
	, refUsrCreate			int		default 0
	, fUsrCreated			date
	, bVisible			tinyint		default 1
	, PRIMARY KEY  (idDocument)
);

CREATE TABLE tbSteps
(
	idStep			int NOT NULL auto_increment
	, refDocument			int		default 0
	, fDate			date
	, refType			int		default 0
	, refOffice			int 	default 0
	, txNotes			text
	, refUsrCreate			int	 default 0
	, fUsrCreated			date
	, bVisible			tinyint		default 1
	, PRIMARY KEY  (idStep)
);

CREATE TABLEUser tbUsers
(
	idUser			int NOT NULL auto_increment
	, PersonalName			varchar(500)
	, userName			varchar(20)
	, userpass			varchar(50)
	,	userlevel			tinyint		default 10
	, bVisible			tinyint		default 1
	, PRIMARY KEY  (idUser)
);

CREATE TABLE tugCategories
(
	idCategory			int NOT NULL auto_increment
	, Category			varchar(200)
	, bVisible			tinyint		default 1
	, PRIMARY KEY  (idCategory)
);

CREATE TABLE tugStepTypes
(
	idStepType			int NOT NULL auto_increment
	, stepType			varchar(100)
	, bVisible			tinyint		default 1
	, PRIMARY KEY  (idStepType)
);

CREATE TABLE tugOffices
(
	idOffice			int NOT NULL auto_increment
	, Office			varchar(500)
	, bVisible			tinyint		default 1			
	, PRIMARY KEY  (idOffice)
);
