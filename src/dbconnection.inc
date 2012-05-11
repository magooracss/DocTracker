<?php


 session_cache_limiter("must-revalidate");
 session_start();  
 session_register ( "session" );

 $linkDB;
 conectDB();


//Basic connection to Database

include ("stringconst.inc");
   
function conectDB()
  {
    global $linkDB;
    
		$linkDB = mysql_connect ("http://000.000.000.000", "USUARIO", "CLAVE");
    
    if (! $linkDB)
      die (STR_ICantConnectDb);
      
    mysql_select_db("BASEDATOS", $linkDB) 
      or die (STR_ICantOpenDb .mysql_error());     
 }

//Get a Row of Table with  Id
function getTbRow ($table, $FieldID, $valueId)
{ 
 global $linkDB;
 
 $result = mysql_query ("SELECT * FROM $table WHERE $fieldID = '$valueId'", $linkDB);
 
 if (! $result )
   die (STR_ERROR_ICantRunQuery .mysql_error());
   
 return mysql_fetch_array ( $result );
}

?>
