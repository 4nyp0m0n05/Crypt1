My equation is e^α=π^β+γ
α [2,inf) , public 
β [1,inf) , private
δ is first digit before dot to π^β example 3.14... -> 3 is δ
Θ=β/2 or (β-1)/2 which helps to find β
encrypt(α,β,path_txt)
decrypt(α,δ,Θ,path_txt)

Problems--
	Plaintext as example:
	asdasdasdasdasdasd1
	12112
	After decrypt:
	asdasdasdasdasdasd112112
	--> problem with newline '\n'


