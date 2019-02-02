ex=csvread('F:\Matlab\subSets1000.txt');
% line�����ϸ�����col�����Ϻ���Ԫ�ص������
[line,col]=size(ex);
%%ͳ�Ƹ�������Ԫ���ܹ���Ҫ�ļ�����
countOfSet=0;

%%����ͳ��Ƶ��
f=zeros(1,line);

c = zeros(1,line);
for i=1:line
    c(1,i)=1;
end

A = zeros(line,line);
for i=1:line
    for j=1:col
        if ex(i,j)~=0
            A(ex(i,j),i)=-1;
        end
    end
end

b = zeros(line,1);
for i=1:line
    b(i,1)=-1;
end

lb = zeros(1,line);
ub = zeros(1,line);
for i=1:line
    ub(1,i)=1;
end

tic
[x,fval] = linprog(c,A,b,[],[],lb,ub);
toc

%%���Ա�Ч��
copyOfX=x;

for i=1:line
    for j=1:line
        if A(i,j) ~=0
            f(1,i)=f(1,i)+1;
        end
    end
end

%%����1/f
maxF= 1/max(f);

%%������֤����Ƿ���ȷ
check=zeros(1,line*3);
pos=1;

%%������
for i=1:line
    if x(i,1) >=maxF
        copyOfX(i,1)=1;
        disp(['S' num2str(i)]);
        countOfSet=countOfSet+1;
        
        %%�����ݷŵ���Ӧ��������
        for j=1:col
            if ex(i,j) ~=0
                check(pos)=ex(i,j);
                pos=pos+1;
            end
        end
        
    else
        copyOfX(i,1)=0;
    end
end

BB=unique(sort(check,2,'ascend'));
disp(BB);

disp(['�ܹ����輯����: ',num2str(countOfSet)]);
disp(['����ʱ��: ',num2str(toc),'ms']);
