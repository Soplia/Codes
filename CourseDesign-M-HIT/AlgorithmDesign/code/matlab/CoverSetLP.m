ex=csvread('F:\Matlab\subSets1000.txt');
% line代表集合个数，col代表集合含有元素的最大数
[line,col]=size(ex);
%%统计覆盖所有元素总共需要的集合数
countOfSet=0;

%%用于统计频率
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

%%看对比效果
copyOfX=x;

for i=1:line
    for j=1:line
        if A(i,j) ~=0
            f(1,i)=f(1,i)+1;
        end
    end
end

%%计算1/f
maxF= 1/max(f);

%%用于验证结果是否正确
check=zeros(1,line*3);
pos=1;

%%输出结果
for i=1:line
    if x(i,1) >=maxF
        copyOfX(i,1)=1;
        disp(['S' num2str(i)]);
        countOfSet=countOfSet+1;
        
        %%把数据放到相应的数组中
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

disp(['总共所需集合数: ',num2str(countOfSet)]);
disp(['运行时间: ',num2str(toc),'ms']);
