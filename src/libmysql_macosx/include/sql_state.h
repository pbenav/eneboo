/* Copyright (C) 2000-2003 MySQL AB

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

/*
  This file includes a mapping from mysql_errno.h to sql_state (as used by
  MyODBC) and jdbc_state.
  It's suitable to include into a C struct for further processing

  The first column is the mysqld server error (declared in mysqld_error.h),
  the second column is the ODBC state (which the 4.1 server sends out by
  default) and the last is the state used by the JDBC driver.
  If the last column is "" then it means that the JDBC driver is using the
  ODBC state.

  The errors in this file are sorted in the same order as in mysqld_error.h
  to allow one to do binary searches for the sqlstate.
*/

ER_DUP_KEY,			"23000", "",
ER_OUTOFMEMORY,			"HY001", "S1001",
ER_OUT_OF_SORTMEMORY,		"HY001", "S1001",
ER_CON_COUNT_ERROR,		"08004", "",
ER_BAD_HOST_ERROR,		"08S01", "",
ER_HANDSHAKE_ERROR,		"08S01", "",
ER_DBACCESS_DENIED_ERROR,	"42000", "",
ER_ACCESS_DENIED_ERROR,		"28000", "",
ER_NO_DB_ERROR,			"3D000", "",
ER_UNKNOWN_COM_ERROR,		"08S01", "",
ER_BAD_NULL_ERROR,		"23000", "",
ER_BAD_DB_ERROR,		"42000", "",
ER_TABLE_EXISTS_ERROR,		"42S01", "",
ER_BAD_TABLE_ERROR,		"42S02", "",
ER_NON_UNIQ_ERROR,		"23000", "",
ER_SERVER_SHUTDOWN,		"08S01", "",
ER_BAD_FIELD_ERROR,		"42S22", "S0022",
ER_WRONG_FIELD_WITH_GROUP,	"42000", "S1009",
ER_WRONG_GROUP_FIELD,		"42000", "S1009",
ER_WRONG_SUM_SELECT,		"42000", "S1009",
ER_WRONG_VALUE_COUNT,		"21S01", "",
ER_TOO_LONG_IDENT,		"42000", "S1009",
ER_DUP_FIELDNAME,		"42S21", "S1009",
ER_DUP_KEYNAME,			"42000", "S1009",
ER_DUP_ENTRY,			"23000", "S1009",
ER_WRONG_FIELD_SPEC,		"42000", "S1009",
ER_PARSE_ERROR,			"42000", "",
ER_EMPTY_QUERY,			"42000" , "",
ER_NONUNIQ_TABLE,		"42000", "S1009",
ER_INVALID_DEFAULT,		"42000", "S1009",
ER_MULTIPLE_PRI_KEY,		"42000", "S1009",
ER_TOO_MANY_KEYS,		"42000", "S1009",
ER_TOO_MANY_KEY_PARTS,		"42000", "S1009",
ER_TOO_LONG_KEY,		"42000", "S1009",
ER_KEY_COLUMN_DOES_NOT_EXITS,	"42000", "S1009",
ER_BLOB_USED_AS_KEY,		"42000", "S1009",
ER_TOO_BIG_FIELDLENGTH,		"42000", "S1009",
ER_WRONG_AUTO_KEY,		"42000", "S1009",
ER_FORCING_CLOSE,		"08S01", "",
ER_IPSOCK_ERROR,		"08S01", "",
ER_NO_SUCH_INDEX,		"42S12", "S1009",
ER_WRONG_FIELD_TERMINATORS,	"42000", "S1009",
ER_BLOBS_AND_NO_TERMINATED,	"42000", "S1009",
ER_CANT_REMOVE_ALL_FIELDS,	"42000", "",
ER_CANT_DROP_FIELD_OR_KEY,	"42000", "",
ER_BLOB_CANT_HAVE_DEFAULT,	"42000", "",
ER_WRONG_DB_NAME,		"42000", "",
ER_WRONG_TABLE_NAME,		"42000", "",
ER_TOO_BIG_SELECT,		"42000", "",
ER_UNKNOWN_PROCEDURE,		"42000", "",
ER_WRONG_PARAMCOUNT_TO_PROCEDURE, "42000", "",
ER_UNKNOWN_TABLE,		"42S02", "",
ER_FIELD_SPECIFIED_TWICE,	"42000", "",
ER_UNSUPPORTED_EXTENSION,	"42000", "",
ER_TABLE_MUST_HAVE_COLUMNS,	"42000", "",
ER_UNKNOWN_CHARACTER_SET,	"42000", "",
ER_TOO_BIG_ROWSIZE,		"42000", "",
ER_WRONG_OUTER_JOIN,		"42000", "",
ER_NULL_COLUMN_IN_INDEX,	"42000", "",
ER_PASSWORD_ANONYMOUS_USER,	"42000", "",
ER_PASSWORD_NOT_ALLOWED,	"42000", "",
ER_PASSWORD_NO_MATCH,		"42000", "",
ER_WRONG_VALUE_COUNT_ON_ROW,	"21S01", "",
ER_INVALID_USE_OF_NULL,		"42000", "",
ER_REGEXP_ERROR,		"42000", "",
ER_MIX_OF_GROUP_FUNC_AND_FIELDS,"42000", "",
ER_NONEXISTING_GRANT,		"42000", "",
ER_TABLEACCESS_DENIED_ERROR,	"42000", "",
ER_COLUMNACCESS_DENIED_ERROR,	"42000", "",
ER_ILLEGAL_GRANT_FOR_TABLE,	"42000", "",
ER_GRANT_WRONG_HOST_OR_USER,	"42000", "",
ER_NO_SUCH_TABLE,		"42S02", "",
ER_NONEXISTING_TABLE_GRANT,	"42000", "",
ER_NOT_ALLOWED_COMMAND,		"42000", "",
ER_SYNTAX_ERROR,		"42000", "",
ER_ABORTING_CONNECTION,		"08S01", "",
ER_NET_PACKET_TOO_LARGE,	"08S01", "",
ER_NET_READ_ERROR_FROM_PIPE,	"08S01", "",
ER_NET_FCNTL_ERROR,		"08S01", "",
ER_NET_PACKETS_OUT_OF_ORDER,	"08S01", "",
ER_NET_UNCOMPRESS_ERROR,	"08S01", "",
ER_NET_READ_ERROR,		"08S01", "",
ER_NET_READ_INTERRUPTED,	"08S01", "",
ER_NET_ERROR_ON_WRITE,		"08S01", "",
ER_NET_WRITE_INTERRUPTED,	"08S01", "",
ER_TOO_LONG_STRING,		"42000", "",
ER_TABLE_CANT_HANDLE_BLOB,	"42000", "",
ER_TABLE_CANT_HANDLE_AUTO_INCREMENT,	"42000", "",
ER_WRONG_COLUMN_NAME,		"42000", "",
ER_WRONG_KEY_COLUMN,		"42000", "",
ER_DUP_UNIQUE,			"23000", "",
ER_BLOB_KEY_WITHOUT_LENGTH,	"42000", "",
ER_PRIMARY_CANT_HAVE_NULL,	"42000", "",
ER_TOO_MANY_ROWS,		"42000", "",
ER_REQUIRES_PRIMARY_KEY,	"42000", "",
ER_CHECK_NO_SUCH_TABLE,		"42000", "",
ER_CHECK_NOT_IMPLEMENTED,	"42000", "",
ER_CANT_DO_THIS_DURING_AN_TRANSACTION,	"25000", "",
ER_NEW_ABORTING_CONNECTION,	"08S01", "",
ER_MASTER_NET_READ,		"08S01", "",
ER_MASTER_NET_WRITE,		"08S01", "",
ER_TOO_MANY_USER_CONNECTIONS,	"42000", "",
ER_READ_ONLY_TRANSACTION,	"25000", "",
ER_NO_PERMISSION_TO_CREATE_USER,"42000", "",
ER_LOCK_DEADLOCK,		"40001", "",
ER_NO_REFERENCED_ROW,		"23000", "",
ER_ROW_IS_REFERENCED,		"23000", "",
ER_CONNECT_TO_MASTER,		"08S01", "",
ER_WRONG_NUMBER_OF_COLUMNS_IN_SELECT,"21000", "",
ER_USER_LIMIT_REACHED,		"42000", "",
ER_NO_DEFAULT,			"42000", "",
ER_WRONG_VALUE_FOR_VAR,		"42000", "",
ER_WRONG_TYPE_FOR_VAR,		"42000", "",
ER_CANT_USE_OPTION_HERE,	"42000", "",
ER_NOT_SUPPORTED_YET,		"42000", "",
ER_WRONG_FK_DEF,		"42000", "",
ER_OPERAND_COLUMNS,		"21000", "",
ER_SUBQUERY_NO_1_ROW,		"21000", "",
ER_ILLEGAL_REFERENCE,		"42S22", "",
ER_DERIVED_MUST_HAVE_ALIAS,	"42000", "",
ER_SELECT_REDUCED,		"01000", "",
ER_TABLENAME_NOT_ALLOWED_HERE,	"42000", "",
ER_NOT_SUPPORTED_AUTH_MODE,	"08004", "",
ER_SPATIAL_CANT_HAVE_NULL,	"42000", "",
ER_COLLATION_CHARSET_MISMATCH,	"42000", "",
ER_WARN_TOO_FEW_RECORDS,	"01000", "",
ER_WARN_TOO_MANY_RECORDS,	"01000", "",
ER_WARN_NULL_TO_NOTNULL,	"01000", "",
ER_WARN_DATA_OUT_OF_RANGE,	"01000", "",
ER_WARN_DATA_TRUNCATED,		"01000", "",
ER_WRONG_NAME_FOR_INDEX,        "42000", "",
ER_WRONG_NAME_FOR_CATALOG,      "42000", "",
ER_UNKNOWN_STORAGE_ENGINE,      "42000", "",
