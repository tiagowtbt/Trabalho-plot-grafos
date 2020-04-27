G = load('grafo.txt')
 
V = [size(G,1),3];


for i=1:1:size(G,1)
   
    x = cos((2*pi*i) / size(G,1));
    y = sin((2*pi*i) / size(G,1));
    
    V(i,2) = x;
    V(i,3) = y;   

endfor

   
   
   
figure(42);
title("representação do grafo");
plot(V(:,2),V(:,3),'*b');  % vertices do grafo
hold on
orden=[];                          
for i=1:1:size(G,1)
   orden(1,i)=sum(G(i,:)); 
end
 
Y=[];
G=triu(G); 
for i=1:1:size(G,1)   %GERA OS CAMINHOS
    for j=1:1:size(G,1)
         
        if G(i,j)==1
          Y=[V(i,2:3);
             V(j,2:3)];
          
          plot(Y(:,1),Y(:,2),'-r')
          hold on
        end
    end    
end
 


A=G;
D=[];
n=0;
if a==0 || a==2
 
   for i=1:1:size(G,1)   %Gera os caminhos percorrendo o grafo
    for j=1:1:size(G,1)
         
        if G(i,j)==1
            n=n+1;
            D(n,:)=[i j];  
        end
    end    
   end 
end

w=0; % contador de trajetórias
X=zeros(size(D,1)+1); % matriz para guardar as tragetórias 
 
F=[];   % vetor que guarda o percurso
gu=D;
while D~=0 
 
   o=randi(size(D,1),1); 
    
   F=D(o,:);   
     
   D(o,:)=[];  
while F(1,1)~=F(1,end)
     
   a=D==F(1,end); %busca trajetórias que terminam em F
   a=a(:,1)+a(:,2); 
   a=logical(a); %guarda as trajetórias possiveis
   M=D(a,:); 
     
    if M==0 
      if size(F,2)==2
       F=[F(1,2) F(1,1)]; 
       a=D==F(1,end); 
       a=a(:,1)+a(:,2); 
       a=logical(a);
       M=D(a,:);
        
      end
    end
  if M~=0   
    r=randi(size(M,1),1);  %escolhe trajetória aleatória para verificação
    
        if F(1,end)==M(r,1)  
             F(1,end+1)=M(r,2);  
        else
             F(1,end+1)=M(r,1);
        end
    
  if F(1,1)~=F(1,end)  % se não abarar as trajetórias
%% elimina as trajetórias sobrando     
      
    k=0;
    for i=1:1:size(D,1) %percorre a matriz de trajetórias
        
        if a(i,1)==1  
          k=k+1;  
            if r==k   
                D(i,:)=[];  
                break   
            end
        end
    end
     
          
  else       
      
    k=0;
    for i=1:1:size(D,1)  
        
        if a(i,1)==1  
          k=k+1;  
            if r==k   
                D(i,:)=[];  
                break   
            end
        end
    end
     

      w=w+1;
      gu=D;  
      X(w,1:size(F,2))=F;
       
 
       
  end 
     
  else   % se não há mais trajetos
        
       w=w+1;  
      
      gu=D;  
       X(w,1:size(F,2))=F;
      
  end
end
   if F(1,1)~=F(1,end) 
       
      break
   end
 
end
 
%impressão do grafo
 
for i=1:1:w   
    a=X(i,:)>0; %Olha as trajetórias diferentes de 0 - que possuem aresta -
    F=X(i,a); 
     
   for n=1:1:size(F,2)-1   % imprime os caminhos
       
          Y=[V(F(1,n),2:3);
             V(F(1,n+1),2:3)];
          figure(i)
          plot(Y(:,1),Y(:,2),'-b')
          hold on
          
   end 
    plot(V(:,2),V(:,3),'*r')  % plota os vertices
    hold on
end
 
% verifica as arestas
 
i=0;
j=0;
while i<=w
    i=i+1;
    a=X(i,:)>0; 
    T=X(i,a);  
    j=0;
   while j<size(T,2)  
      j=j+1 
     a=X(:,1)==X(i,j);  
     a(i,1)=0;    
      
     if sum(a)~=0   
       b=X(a,:); 
       d=b>0;  
       B=b(d);  
        
       S1=T(1,1:j-1) 
       S2=T(1,j+1:end)
       F=[S1 B S2]  
        
       X(i,1:size(F,2))=F;  
       X(a,:)=[];  
       i=1;
       a=X(i,:)>0; 
       T=X(i,a);  
     end       
   end
end
 
 
b=X(1,:); % pega as trajetórias 
d=b>0;  %elimina os 0
F=b(d)
if w~=1
for n=1:1:size(F,2)-1   %gera as trajetórias com fim no grafo
       
          Y=[V(F(1,n),2:3);
             V(F(1,n+1),2:3)];
          figure(1000+i)
          plot(Y(:,1),Y(:,2),'-b')
          hold on
          
end 
   plot(V(:,2),V(:,3),'*r')  % vertices do grafo
   title("representação do grafo")
end
