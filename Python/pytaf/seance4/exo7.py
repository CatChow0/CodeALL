import random

def start():
    sujet = ['Je','Tu','Il','Elle','Nous','Vous','Ils','Elles']
    # 8
    verbe = ['abaisserr','abandonner','abaisser','arranger','arrêter','arriver','arrondir','arroser','aspirer','assagir','assaillir','assainir','assassiner','assembler','assener','asséner','asseoir','asservir','assiéger','assimiler','assister','associer','assombrir','assommer','assortir','assoupir','assouplir','assouvir','assujettir','assumer','assurer','astreindre','attacher','attaquer','attarder','atteindre','atteler','attendre','attendrir','attenter','atténuer','atterrer','atterrir','attester','attirer','attiser','attraper','attribuer','augmenter','autoriser','autosuggestionner','avaler','avancer','aventurer','avérer','avertir','aviser','avoir','avouer','avoyer','axer']
    # 61
    complement = ['abaisser','abandonner','abasourdir','abattre','abêtir','abhorrer','abîmer','abolir','abonder','abonner','aborder','aboutir','aboyer','abréger','abreuver','abriter','abrutir','absenter','absoudre','abstenir','abstraire','abuser','accabler','accaparer','accéder','accélérer','accentuer','accepter','accoler','accommoder','accompagner','accomplir','accorder','accoucher','accourir','accrocher','accroire','accroître','accroupir','accueillir','accumuler','accuser','acharner','acheminer','acheter','achever','aciérer','aciseler','acquérir','acquiescer','acquitter','acter','activer','actualiser','adapter','additionner','adhérer','adire','adjoindre','admettre','administrer','admirer','adonner','adopter','adorer','adoucir','adresser','advenir','aérer','affaiblir','affecter','affectionner','afférer','affermir','afficher','affiner','affirmer','affliger','affoler','affranchir','affronter','agacer','agenouiller','aggraver','agir','agiter','agonir','agrafer','agrandir','agréer','agréger','agresser','agripper','aguerrir','aider','aiguiller','aiguiser','ailler','aimer','airer','ajouter','alerter','aliéner','aligner','alimenter','aliter','allécher','alléger','alléguer','aller','allier','allonger','allouer','allumer','alourdir','altérer','aluner','alunir','amarrer','amasser','améliorer','aménager','amener','amenuiser','amerrir','amoindrir','amonceler','amorcer','amortir','amourer','amplifier','amuïr','amuser','analyser','anéantir','animer','annihiler','annoncer','annoter','annuler','anticiper','apaiser','apercevoir','apeurer','apitoyer','aplanir','aplatir','apparaître','apparenter','apparier','apparoir','appartenir','appauvrir','appeler','appendre','applaudir','appliquer','apporter','apposer','apprécier','appréhender','apprendre','apprêter','approcher','approfondir','approprier','approuver','approvisionner','appuyer','arborer','arguer','arracher','arranger','arrêter','arriver','arrondir','arroser','aspirer','assagir','assaillir','assainir','assassiner','assembler','assener','asséner','asseoir','asservir','assiéger','assimiler','assister','associer','assombrir','assommer','assortir','assoupir','assouplir','assouvir','assujettir','assumer','assurer','astreindre','attacher','attaquer','attarder','atteindre','atteler','attendre','attendrir','attenter','atténuer','atterrer','atterrir','attester','attirer','attiser','attraper','attribuer','augmenter','autoriser','autosuggestionner','avaler','avancer','aventurer','avérer','avertir','aviser','avoir','avouer','avoyer','axer' ]
    #230
    nb = int(input('Nombre de phrase a generer: '))
    if nb >0:
        for i in range (nb):
            s_nb = random.randint(0,7)
            v_nb = random.randint(0,60)
            c_nb = random.randint(0,229)
            print(sujet[s_nb],verbe[v_nb],complement[c_nb])
    else:
        print('0 n\'est pas disponible')
        start()
        
start()