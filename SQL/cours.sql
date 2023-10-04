-- afficher une colonne precise
SELECT prenom, nom FROM employes;
-- eviter les doublons
SELECT DISTINCT(service) FROM employes;
-- Selection avec condition
SELECT prenom FROM employes WHERE service = "informatique";
--Selectioner une perdiode temporel
SELECT prenom, nom, date_embauche FROM employes WHERE date_embauche BETWEEN '2008-01-01' AND '2012-10-24';
-- Combo
SELECT prenom, nom, date_embauche FROM employes WHERE date_embauche BETWEEN '2008-01-01' AND CURDATE();
-- Sele"ct prenom start with s
SELECT prenom, nom FROM employes WHERE prenom LIKE 's%';
SELECT prenom, nom FROM employes WHERE prenom LIKE '%s';
SELECT prenom, nom FROM employes WHERE prenom LIKE '%s%';
-- Select tout sauf
SELECT prenom, nom, service FROM employes WHERE service != 'informatique';
-- Select salair > 3000
SELECT prenom, nom, salaire FROM employes WHERE salaire > 3000;

SELECT prenom, nom FROM employes ORDER BY prenom ASC LIMIT 5,5;

-- EXO
SELECT prenom, service FROM employes;

SELECT DISTINCT(service) FROM employes;

SELECT prenom, nom, date_embauche FROM employes ORDER BY date_embauche;

SELECT prenom, nom, sex FROM employes

