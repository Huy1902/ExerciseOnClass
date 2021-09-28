program Min;

Const
   fi = 'MIN.INP';
   fo = 'MIN.OUT';


var
   n, res : int64;
   k : longint;

function FindMin( x : int64 ) : longint;
begin
   if x = 0 then FindMin := 0
   else if x mod 10 = 5 then FindMin := 1 + FindMin( x div 10 )
   else FindMin := FindMin( x div 10 );
end;

Procedure InputFile;
Var
   f : text;
begin
   assign(f,fi);
   reset(f);
   readln(f, n, k );
   close(f);
end;

Procedure OutputFile;
Var
   f : text;
Begin
   n := n + 1;

   res := 1;
   while true do
     begin
      if FindMin(n) >= k then break;

      while (n div res) mod 10 = 5 do
         res := res * 10;

      n := n + res;
   end;
   assign(f,fo);
   rewrite(f);
   writeln(f, n );
   close(f);
end;

Begin
  InputFile;
  OutputFile;
end.

